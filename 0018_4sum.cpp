class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<int> quads;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    int l = nums[left], r = nums[right];
                    if (sum == target) {
                        quads.push_back(nums[i]);
                        quads.push_back(nums[j]);
                        quads.push_back(nums[left]);
                        quads.push_back(nums[right]);
                        while (left < right && nums[left] == l) ++left;
                        while (left < right && nums[right] == r) --right;
                    }
                    else if (sum > target) while (left < right && nums[right] == r) --right;
                    else while (left < right && nums[left] == l) ++left;
                }
            }
        }
        vector<vector<int>> result;
        int n = quads.size() / 4;
        result.reserve(n);
        for (int i = 0; i < quads.size(); i += 4) {
            result.emplace_back(quads.begin() + i, quads.begin() + i + 4);
        }
        return result;
    }
};

