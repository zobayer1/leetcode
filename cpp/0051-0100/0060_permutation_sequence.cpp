#include <string>
#include <vector>

using namespace std;

/* 60. Permutation Sequence */

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorials[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector <char> digits;
        for (int i = 0; i < n; i++) digits.push_back(i+'1');
        k--;
        int fact = factorials[n];
        int idx;
        string res = "";
        for (int i = n; i > 0; i--) {
            fact = fact / i;
            idx = k / fact;
            k = k % fact;
            res += digits[idx];
            digits.erase(digits.begin() + idx);
        }
        return res;
    }
};
