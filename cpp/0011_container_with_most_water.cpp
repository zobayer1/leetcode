#include <vector>

using namespace std;

/* 11. Container With Most Water */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), mx = 0;
        for (int i = 0, j = n - 1; i < j; height[i] < height[j] ? ++i : --j) {
            mx = max(mx, (j - i) * min(height[i], height[j]));
        }
        return mx;
    }
};
