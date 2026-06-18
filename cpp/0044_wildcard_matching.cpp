#include <string>

using namespace std;

/* 44. Wildcard Matching */

class Solution {
public:
    bool isMatch(string s, string p) {
        int dp[2][2001] = {0};
        int n = s.size(), m = p.size();
        for (int i = n; i >= 0; i--) {
            dp[i&1][m] = (i == n);
            for (int j = m-1; j >= 0; j--) {
                if (p[j] == '*') dp[i&1][j] = dp[i&1][j + 1] || (i < n && dp[(i + 1)&1][j]);
                else if (i < n && (p[j] == '?' || s[i] == p[j])) dp[i&1][j] = dp[(i+1)&1][j+1];
                else dp[i&1][j] = 0;
            }
        }
        return dp[0][0];
    }
};
