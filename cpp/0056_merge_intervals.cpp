#include <algorithm>
#include <vector>

using namespace std;

/* 56. Merge Intervals */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector < vector <int> > res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector< int >& last = res.back();
            if (last[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                last[1] = max(last[1], intervals[i][1]);
            }
        }
        return res;
    }
};
