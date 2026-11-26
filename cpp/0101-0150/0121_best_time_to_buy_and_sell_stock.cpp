#include <algorithm>
#include <vector>

using namespace std;

/* 121. Best Time to Buy and Sell Stock */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        int profit = 0, minCost = prices[0];
        for (int i = 1; i < n; i++) {
            profit = max(profit, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }
        return profit;
    }
};
