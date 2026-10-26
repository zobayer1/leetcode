#include <algorithm>
#include <vector>

using namespace std;

/* 55. Jump Game */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currjump = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n - 1; i++) {
            currjump = max(currjump, i + nums[i]);
            if (currjump <= i) return false;
            if (currjump >= n-1) return true;
        }
        return currjump >= n-1;
    }
};
