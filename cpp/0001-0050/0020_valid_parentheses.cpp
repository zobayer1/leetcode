#include <stack>
#include <string>

using namespace std;

/* 20. Valid Parentheses */


class Solution {

    bool oppose(char p1, char p2) {
        switch(p1) {
            case '(': return p2 == ')';
            case ')': return p2 == '(';
            case '{': return p2 == '}';
            case '}': return p2 == '{';
            case '[': return p2 == ']';
            case ']': return p2 == '[';
        }
        return false;
    }
public:
    bool isValid(string s) {
        stack <char> st;
        for (char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if (st.empty()) return false;
            else {
                char t = st.top(); st.pop();
                if (!oppose(t, ch)) return false;
            }
        }
        return st.empty();
    }
};
