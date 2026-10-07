#include <string>
#include <vector>

using namespace std;

/* 22. Generate Parentheses */

class Solution {
    vector<string> paths;

    void walk(int a, int b, int s, string& curr) {
        if (!a && !b) {
            paths.push_back(curr);
            return;
        }
        if (a) {
            curr.push_back('(');
            walk(a-1, b, s+1, curr);
            curr.pop_back();
        }
        if (b && s > 0) {
            curr.push_back(')');
            walk(a, b-1, s-1, curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        walk(n, n, 0, curr);
        return paths;
    }
};
