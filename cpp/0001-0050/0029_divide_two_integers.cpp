#include <cstdint>

/* 29. Divide Two Integers */

const int32_t max_32bit = INT32_MAX;
const int32_t min_32bit = INT32_MIN;

long long iabs(long long x) {
    if (x < 0) return -x;
    return x;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == min_32bit && divisor == 1) return min_32bit;
        if (dividend == min_32bit && divisor == -1) return max_32bit;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long ldividend = iabs((long long)dividend);
        long long ldivisor = iabs((long long)divisor);

        int quotient = 0;
        while (ldividend >= ldivisor) {
            int shift = 0;
            while (ldividend >= (ldivisor << (shift+1))) shift++;
            ldividend -= (ldivisor << shift);
            quotient += (1 << shift);
        }
        
        if (negative) quotient = -quotient;
        return quotient;
    }
};
