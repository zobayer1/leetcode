#include <algorithm>
#include <vector>

using namespace std;

/* 46. Permutations */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        sort(nums.begin(), nums.end());
        do {
            perms.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return perms;
    }
};
