#include <algorithm>
#include <string>

using namespace std;

/* 67. Add Binary */

class Solution {
public:
    string addBinary(string a, string b) {
        int na = (int)a.size(), nb = (int)b.size();
        int n = max(na, nb);
        string v;
        v.reserve(n+1);
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int ai = 0, bi = 0;
            if (i < na) ai = int(a[na-1-i]-'0');
            if (i < nb) bi = int(b[nb-1-i]-'0');
            int s = ai + bi + carry;
            v.push_back((s&1) + '0');
            carry = s >> 1;
        }
        if (carry > 0) v.push_back(carry + '0');
        reverse(v.begin(), v.end());
        return v;
    }
};
