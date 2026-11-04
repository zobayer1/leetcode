/* 69. Sqrt(x) */

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int lo = 0, hi = x;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == x / mid) return mid;
            if (mid < x / mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }
};
