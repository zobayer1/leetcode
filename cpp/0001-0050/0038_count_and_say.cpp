#include <string>

using namespace std;

/* 38. Count and Say */

class Solution {
    string rle(const string& s) {
        string result;
        result.reserve(2 * s.size());
        char ch = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (ch != s[i]) {
                if (cnt) {
                    result += to_string(cnt);
                    result.push_back(ch);
                }
                ch = s[i];
                cnt = 0;
            }
            cnt++;
        }
        if (cnt) {
            result += to_string(cnt);
            result.push_back(ch);
        }
        return result;
    }
public:
    string countAndSay(int n) {
        string boom = "1";
        for (int i = 2; i <= n; i++) boom = rle(boom);
        return boom;
    }
};
