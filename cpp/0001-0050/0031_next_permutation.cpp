#include <algorithm>
#include <vector>

using namespace std;

/* 31. Next Permutation */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};