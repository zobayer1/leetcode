#include <algorithm>
#include <string>
#include <string_view>

using namespace std;

/* 65. Valid Number */

class Solution {
    bool isValidChars(string_view s) {
        for (char c : s)
            if (c != 'E' && c != 'e' && (c < '0' || c > '9') && c != '+' && c != '-' && c != '.')
                return false;
        return true;
    }

    size_t findExPos(string_view s) {
        size_t first = s.find_first_of("eE");
        if (first == string_view::npos) return s.size();
        
        size_t last = s.find_last_of("eE");
        if (first != last) return -1;
        
        return first;
    }

    size_t findDotPos(string_view s) {
        size_t first = s.find_first_of('.');
        if (first == string_view::npos) return s.size();
        
        if (s.find_last_of('.') != first) return -1;
        return first;
    }

    bool isInteger(string_view s) {
        if (s.empty()) return false;
        return all_of(s.begin(), s.end(), [](char c) { return c >= '0' && c <= '9'; });
    }
public:
    bool isNumber(string s) {
        string_view sv(s);
        if (!isValidChars(sv)) return false;

        size_t exPos = findExPos(sv);
        if (exPos == -1) return false;

        if (exPos < sv.size()) {
            string_view exponent = sv.substr(exPos + 1);
            if (exponent.empty()) return false;
            
            if (exponent[0] == '+' || exponent[0] == '-') {
                exponent.remove_prefix(1);
            }
            if (!isInteger(exponent)) return false;
        }

        string_view number = sv.substr(0, exPos);
        if (number.empty()) return false;

        if (number[0] == '+' || number[0] == '-') {
            number.remove_prefix(1);
        }
        if (number.empty()) return false;
        
        size_t dotPos = findDotPos(number);
        if (dotPos == -1) return false;
        if (dotPos == number.size()) return isInteger(number);

        string_view before = number.substr(0, dotPos);
        string_view after = number.substr(dotPos + 1);
        
        if (before.empty() && after.empty()) return false;
        if (!before.empty() && !isInteger(before)) return false;
        if (!after.empty() && !isInteger(after)) return false;

        return true;
    }
};
