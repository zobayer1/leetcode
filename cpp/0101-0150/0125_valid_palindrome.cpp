#include <string>

using namespace std;

/* 125. Valid Palindrome */

class Solution {
    inline bool convAlphaNum(char &ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) return true;
        if (ch >= 'A' && ch <= 'Z') {
            ch = char(ch + 32);
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            char chi = s[i], chj = s[j];
            bool vi = convAlphaNum(chi);
            if (!vi) {
                i++;
                continue;
            }
            bool vj = convAlphaNum(chj);
            if (!vj) {
                j--;
                continue;
            }
            if (chi != chj) break;
            i++;
            j--;
        }
        return i >= j;
    }
};
