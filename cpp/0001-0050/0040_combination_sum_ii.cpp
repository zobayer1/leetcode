#include <algorithm>
#include <vector>

using namespace std;

/* 40. Combination Sum II */

class Solution {
    vector< vector< int > > results;
    vector< int > current;

    void backtrack(int start, int remain, vector<int>& candidates) {
        if (remain == 0) {
            results.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) return;
            if (i > start && candidates[i] == candidates[i-1]) continue;
            current.push_back(candidates[i]);
            backtrack(i+1, remain - candidates[i], candidates);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates);
        return results;
    }
};
