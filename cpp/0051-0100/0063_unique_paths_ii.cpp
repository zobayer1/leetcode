#include <vector>

using namespace std;

/* 63. Unique Paths II */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;

        vector< vector< long long > > dp;
        dp.resize(m);
        for (int i = 0; i < m; i++) dp[i].resize(n);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) dp[i][j] = obstacleGrid[i][j] ^ 1;

        for (int i = m-2; i >= 0; i--) if (!dp[i][n-1]) for (i=i-1; i >= 0; i--) dp[i][n-1] = 0;
        for (int i = n-2; i >= 0; i--) if (!dp[m-1][i]) for (i=i-1; i >= 0; i--) dp[m-1][i] = 0;
        for (int i = m-2; i >= 0; i--) for (int j = n-2; j >= 0; j--) if (dp[i][j]) dp[i][j] = dp[i+1][j] + dp[i][j+1];
        
        return (int)dp[0][0];
    }
};
