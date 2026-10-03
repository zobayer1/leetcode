class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2][21] = {0};
        int n = (int)s.size(), m = (int)p.size();
        for (int i = n; i >= 0; --i) {
            dp[i & 1][m] = (i == n);
            for (int j = m - 1; j >= 0; --j) {
                if (j + 1 < m && p[j + 1] == '*') {
                    dp[i & 1][j] = dp[i & 1][j+2] || (i < n && (s[i] == p[j] || p[j] == '.') && dp[(i+1) & 1][j]);
                } else {
                    dp[i & 1][j] = i < n && (s[i] == p[j] || p[j] == '.') && dp[(i+1) & 1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
