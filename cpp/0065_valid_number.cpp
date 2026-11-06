#include <string>
#include <string_view>

using namespace std;

/* 65. Valid Number */

class Solution {
    bool isValidChars(const string_view s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'E' && s[i] != 'e' && (s[i] < '0' || s[i] > '9') && s[i] != '+' && s[i] != '-' && s[i] != '.') return false;
        }
        return true;
    }

    int findExPos(const string_view s) {
        int len = (int) s.size();
        int idx = len;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'E' || s[i] == 'e') {
                if (idx != len) return -1;
                idx = i;
            }
        }
        return idx;
    }

    int findDotPos(const string_view s) {
        int len = (int) s.size();
        int idx = len;
        for (int i = 0; i < len; i++) {
            if (s[i] == '.') {
                if (idx != len) return -1;
                idx = i;
            }
        }
        return idx;
    }

    bool isInteger(const string_view s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
public:
    bool isNumber(string s) {
        string_view sv(s);
        if (!isValidChars(sv)) return false;

        int exPos = findExPos(sv);
        if (exPos == -1) return false;

        if (exPos < sv.size()) {
            string_view exponent = sv.substr(exPos+1);
            if (exponent.size() == 0) return false;
            string_view expval;
            if (exponent[0] == '+' || exponent[0] == '-') expval = exponent.substr(1);
            else expval = exponent;
            if (expval.size() == 0 || !isInteger(expval)) return false;
        }

        string_view number = sv.substr(0, exPos);
        if (number.size() == 0) return false;

        string_view numval;
        if (number[0] == '+' || number[0] == '-') numval = number.substr(1);
        else numval = number;
        if (numval.size() == 0) return false;
        
        int dotPos = findDotPos(numval);
        if (dotPos == -1) return false;
        if (dotPos == numval.size()) return isInteger(numval);

        string_view before = numval.substr(0, dotPos);
        string_view after = numval.substr(dotPos+1);
        if (before.size() + after.size() == 0) return false;
        if (before.size() > 0 && !isInteger(before)) return false;
        if (after.size() > 0 && !isInteger(after)) return false;

        return true;
    }
};
