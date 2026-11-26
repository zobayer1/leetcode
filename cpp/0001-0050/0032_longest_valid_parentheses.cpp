#include <algorithm>
#include <string>
using namespace std;

/* 32. Longest Valid Parentheses */

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int n = (int) s.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            if (left == right) mx = max(mx, right << 1);
            if (right > left) left = right = 0;
        }
        left = right = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            if (left == right) mx = max(mx, right << 1);
            if (left > right) left = right = 0;
        }
        return mx;
    }
};
