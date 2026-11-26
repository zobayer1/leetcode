#include <string>
#include <vector>

using namespace std;

/* 14. Longest Common Prefix */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j, done;
        for (j = done = 0; j < strs[0].size(); ++j) {
            for (int i = 0; i < strs.size(); ++i) {
                if (j >= strs[i].size()) { done = 1; break; }
                if (strs[i][j] != strs[0][j]) { done = 1; break; }
            }
            if (done) break;
        }
        return strs[0].substr(0, j);
    }
};
