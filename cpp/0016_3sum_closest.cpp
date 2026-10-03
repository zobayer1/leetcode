class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(closest - target)) closest = sum;
                int l = nums[j], r = nums[k];
                if (sum < target) while (j < k && nums[j] == l) ++j;
                else while (j < k && nums[k] == r) --k;
            }
        }
        return closest;
    }
};
