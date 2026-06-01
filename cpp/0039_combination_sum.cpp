#include <algorithm>
#include <vector>

using namespace std;

/* 39. Combination Sum */

class Solution {
    vector< vector< int > > results;
    vector< int > current;

    void backtrack(int start, int remain, vector<int>& candidates) {
        if (remain == 0) {
            results.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) {
                return;
            }
            current.push_back(candidates[i]);
            backtrack(i, remain - candidates[i], candidates);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates);
        return results;
    }
};
