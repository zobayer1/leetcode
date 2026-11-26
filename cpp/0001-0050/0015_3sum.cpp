#include <algorithm>
#include <vector>

using namespace std;

/* 15. 3Sum */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> ftriplets;
        sort(nums.begin(), nums.end());
        if (nums.back() < 0) return {};
        for (int i = 0; i <= nums.size() - 3 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int l = nums[j], r = nums[k];
                if (sum == 0) {
                    ftriplets.push_back(nums[i]), ftriplets.push_back(nums[j]), ftriplets.push_back(nums[k]);
                    while (j < k && nums[j] == l) ++j;
                    while (j < k && nums[k] == r) --k;
                }
                else if (sum > 0) while (j < k && nums[k] == r) --k;
                else while (j < k && nums[j] == l) ++j;
            }
        }
        vector<vector<int>> result;
        int n = ftriplets.size() / 3;
        result.reserve(n);
        for (int i = 0; i < ftriplets.size(); i += 3) {
            result.emplace_back(ftriplets.begin() + i, ftriplets.begin() + i + 3);
        }
        return result;
    }
};
