#include <climits>

/* 7. Reverse Integer */

class Solution {
public:
    int safe_calc(int a, int digit, bool &overflow) {
        if (a > INT_MAX / 10) { overflow = true; return 0; }
        if (a < INT_MIN / 10) { overflow = true; return 0; }
        int temp = a * 10;
        if (digit > 0 && temp > INT_MAX - digit) { overflow = true; return 0; }
        if (digit < 0 && temp < INT_MIN - digit) { overflow = true; return 0; }
        temp += digit;
        return temp;
    }
    int reverse(int x) {
        int ret = 0;
        bool overflow = false;
        while (x != 0) {
            ret = safe_calc(ret, x % 10, overflow);
            if (overflow) return 0;
            x /= 10;
        }
        return ret;
    }
};
