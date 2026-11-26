#include <vector>
#include <utility>

using namespace std;

/* 41. First Missing Positive */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                int k = nums[i]-1;
                swap(nums[i], nums[k]);
            }
        }
        for (int i = 0; i < n; i++) if (nums[i] != i+1) return i+1;
        return n+1;
    }
};
