#include <algorithm>

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ret = 0;
        int i = static_cast<int>(cost.size());
        while (i > 0) {
            ret += cost[--i];
            if (i > 0) ret += cost[--i];
            i--;
        }
        return ret;
    }
};
