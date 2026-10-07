#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

/* 301. Remove Invalid Parentheses */

class Solution {
    set<string> paths[27][27];
    bool vis[27][27] = {0};
    int dp[27][27] = {0};

    set<string> walk(int i, int b, string &s) {
        if (i == static_cast<int>(s.size())) {
            if (b == 0) return {""};
            return {};
        }

        if (vis[i][b]) return paths[i][b];

        set<string> ans, suffixes;
        if (s[i] == '(') {
            if (dp[i][b] == 1 + dp[i+1][b]) {
                suffixes = walk(i + 1, b, s);
                for (const string& suffix : suffixes) ans.insert(suffix);
            }
            if (dp[i][b] == dp[i + 1][b + 1]) {
                suffixes = walk(i+1, b+1, s);
                for (const string& suffix : suffixes) ans.insert("(" + suffix);
            }
        } else if (s[i] == ')') {
            if (dp[i][b] == 1 + dp[i+1][b]) {
                suffixes = walk(i+1, b, s);
                for (const string& suffix : suffixes) ans.insert(suffix);
            }
            if (b > 0 && dp[i][b] == dp[i + 1][b - 1]) {
                suffixes = walk(i+1, b-1, s);
                for (const string& suffix : suffixes) ans.insert(")" + suffix);
            }
        } else {
            suffixes = walk(i+1, b, s);
            for (const string& suffix : suffixes) ans.insert(string(1, s[i]) + suffix);
        }
        paths[i][b] = ans;
        vis[i][b] = 1;
        return ans;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = static_cast<int>(s.size());
        for (int i = 1; i < 26; i++) dp[n][i] = 1 << 20;
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b <= n; b++) {
                if (s[i] != '(' && s[i] != ')') dp[i][b] = dp[i+1][b];
                else if (s[i] == '(') dp[i][b] = min(1 + dp[i+1][b], dp[i+1][b+1]);
                else {
                    dp[i][b] = 1 + dp[i+1][b];
                    if (b > 0) dp[i][b] = min(dp[i][b], dp[i+1][b-1]);
                }
            }
        }
        
        set<string> ans = walk(0, 0, s);
        vector<string> result(ans.begin(), ans.end());
        return result;
    }
};
