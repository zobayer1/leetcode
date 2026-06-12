#include <algorithm>
#include <vector>

using namespace std;

/* 35. Search Insert Position */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
