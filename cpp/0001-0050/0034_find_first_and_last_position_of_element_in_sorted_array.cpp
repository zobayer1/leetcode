#include <algorithm>
#include <vector>

using namespace std;

/* 34. Find First and Last Position of Element in Sorted Array */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(nums.begin(), nums.end(), target);
        if (range.first == nums.end() || *(range.first) != target) return {-1, -1};
        return {static_cast<int>(range.first - nums.begin()), static_cast<int>((range.second - 1) - nums.begin())};
    }
};
