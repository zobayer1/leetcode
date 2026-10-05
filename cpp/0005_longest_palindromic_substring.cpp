#include <string>
#include <vector>

using namespace std;

/* 5. Longest Palindromic Substring */

class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        t.reserve(2 * s.length() + 3);
        t += "^";
        for (char c: s) {
            t += '#';
            t += c;
        }
        t += "#$";
        
        int n = static_cast<int>(t.length());
        int center = 0, right = 0;
        vector<int> P(n, 0);
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (i < right) P[i] = min(right - i, P[mirror]);
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) P[i]++;
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }

        int maxlen = 0, center_idx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxlen) {
                maxlen = P[i];
                center_idx = i;
            }
        }
        
        int start = (center_idx - maxlen) / 2;
        return s.substr(start, maxlen);
    }
};
