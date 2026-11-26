#include <algorithm>
#include <vector>

using namespace std;

/* 57. Insert Interval */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector< vector< int > > res;
        int low = newInterval[0], hi = newInterval[1];
        int lt, rt;
        int n = intervals.size();
        for (lt = 0; lt < n; lt++) if (intervals[lt][1] >= low) break;
        for (rt = n-1; rt >= 0; rt--) if (intervals[rt][0] <= hi) break;
        if (lt > 0) res.insert(res.end(), intervals.begin(), intervals.begin()+lt);
        if (lt >= 0 && lt < n) low = min(low, intervals[lt][0]);
        if (rt >= 0 && rt < n) hi = max(hi, intervals[rt][1]);
        res.push_back({low, hi});
        if (rt+1<n) res.insert(res.end(), intervals.begin()+rt+1, intervals.end());
        return res;
    }
};
