#include <algorithm>
#include <vector>

using namespace std;

/* 45. Jump Game II */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return 0;
        int last = 0, jumps = 0, range = 0;
        for (int i = 0; i < n - 1; i++) {
            range = max(range, i+nums[i]);
            if (i == last) {
                last = range;
                jumps++;
                if (last >= n-1) break;
            }
        }
        return jumps;
    }
};
