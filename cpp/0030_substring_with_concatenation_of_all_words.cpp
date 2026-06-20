#include <map>
#include <string>
#include <vector>

using namespace std;

/* 30. Substring with Concatenation of All Words */

using int64 = long long;

const int maxlen = 10001;
const int maxwords = 5001;
const int primebase = 31;
const int primemod = 1000000007;

int modpow(int n, int p, int m) {
    int64 res = 1;
    int64 base = n % m;
    while (p > 0) {
        if (p & 1 == 1) res = (res * base) % m;
        base = (base * base) % m;
        p /= 2;
    }
    return (int) res;
}

int rabin_karp(const string& s) {
    int64 hash = 0;
    for (int i = 0; i < s.size(); i++) hash = (hash * primebase + int(s[i])) % primemod;
    return hash;
}

class Solution {
    map<int, int> hashes;
    int need[maxwords] = {0};
    int seen[maxwords] = {0};
    int idx[maxlen] = {0};

    void generate_hashes(const vector<string>& words) {
        int id = 1;
        for (const string& word : words) {
            int hash = rabin_karp(word);
            int& eid = hashes[hash];
            if (!eid) eid = id++;
            need[eid]++;
        }
    }

    void rolling_hashes(const string& s, int l) {
        int high = modpow(primebase, l-1, primemod);
        int64 hash = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i >= l) hash = ((hash-int64(s[i-l])*high)%primemod + primemod) % primemod;
            hash = (hash*primebase + int(s[i])) % primemod;
            if (i >= l-1) idx[i-l+1] = hashes[(int) hash];
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wlen = (int) words[0].size();
        generate_hashes(words);
        rolling_hashes(s, wlen);
        vector<int> results;
        for (int i = 0; i < wlen; i++) {
            int left = i, right = i, total = 0;
            for (; right+wlen <=s.size(); right += wlen) {
                int rid = idx[right];
                if (rid == 0) {
                    for (; left <= right; left += wlen) {
                        int lid = idx[left];
                        if (lid > 0) {
                            seen[lid]--;
                            total--;
                        }
                    }
                    continue;
                }
                seen[rid]++;
                total++;
                while (seen[rid] > need[rid]) {
                    int lid = idx[left];
                    if (lid > 0) {
                        seen[lid]--;
                        total--;
                    }
                    left += wlen;
                }
                if (total == words.size()) {
                    results.push_back(left);
                    seen[idx[left]]--;
                    total--;
                    left += wlen;
                }
            }
            for (; left < right; left += wlen) seen[idx[left]]--;
        }
        return results;
    }
};
