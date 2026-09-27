class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long t = x, r = 0;
        while (t) {
            r = r * 10 + t % 10;
            t /= 10;
        }
        return r == x;
    }
};

