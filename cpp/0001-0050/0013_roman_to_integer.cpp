#include <string>

using namespace std;

/* 13. Roman to Integer */

class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'M') val += 1000;
            else if (s[i] == 'D') val += 500;
            else if (s[i] == 'C') {
                if (i + 1 < s.size() && s[i + 1] == 'M') val += 900, ++i;
                else if (i + 1 < s.size() && s[i + 1] == 'D') val += 400, ++i;
                else val += 100;
            }
            else if (s[i] == 'L') val += 50;
            else if (s[i] == 'X') {
                if (i + 1 < s.size() && s[i + 1] == 'C') val += 90, ++i;
                else if (i + 1 < s.size() && s[i + 1] == 'L') val += 40, ++i;
                else val += 10;
            }
            else if (s[i] == 'V') val += 5;
            else if (s[i] == 'I') {
                if (i + 1 < s.size() && s[i + 1] == 'X') val += 9, ++i;
                else if (i + 1 < s.size() && s[i + 1] == 'V') val += 4, ++i;
                else val += 1;
            }
        }
        return val;
    }
};
