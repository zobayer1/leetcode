#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

/* 49. Group Anagrams */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< string, vector< string > > anagrams;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            anagrams[t].push_back(s);
        }
        vector< vector< string > > res;
        for (auto item : anagrams) {
            res.push_back(item.second);
        }
        return res;
    }
};
