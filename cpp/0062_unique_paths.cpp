#include <algorithm>
#include <numeric>

using namespace std;

/* 62. Unique Paths */

class Solution {
    int choose(int m, int n) {
        int k = std::min(m, n);
        int total = m + n;
        
        int res = 1;
        
        for (int i = 1; i <= k; ++i) {
            int numerator = total - k + i;
            int denominator = i;
            
            int g = std::gcd(res, denominator);
            res /= g;
            denominator /= g;
            
            g = std::gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;
            
            res *= numerator;
        }
        
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return choose(m-1, n-1);
    }
};
