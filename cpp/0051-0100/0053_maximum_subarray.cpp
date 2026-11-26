#include <algorithm>
#include <vector>

using namespace std;

/* 53. Maximum Subarray */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0], currsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currsum = max(nums[i], currsum + nums[i]);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
