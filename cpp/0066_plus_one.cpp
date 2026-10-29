#include <algorithm>
#include <vector>

using namespace std;

/* 66. Plus One */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = (int) digits.size();
        vector< int > v;
        v.resize(n);
        bool done = false;
        for (int i = n - 1; i >= 0; i--) {
            if (!done) {
                int s = digits[i] + carry;
                v[n-i-1] = s % 10;
                carry = s / 10;
                if (!carry) done = true;
            } else v[n-i-1] = digits[i];
        }
        if (carry) v.push_back(carry);
        reverse(v.begin(), v.end());
        return v;
    }
};
