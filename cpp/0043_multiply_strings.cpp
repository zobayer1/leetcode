#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 43. Multiply Strings */

class Solution {
    string mul(const string& a, const string& b) {
        string res;
        res.resize(a.size()+b.size());
        fill(res.begin(), res.end(), '0');
        for (int i = b.size()-1; i >= 0; i--) {
            int carry = 0;
            int k = b.size()-1-i;
            int ib = int(b[i]-'0');
            for (int j = a.size() - 1; j >= 0; j--) {
                int ia = int(a[j]-'0');
                int ir = int(res[k]-'0');
                int p = ia * ib + ir + carry;
                res[k++] = char(p%10 + '0');
                carry = p / 10;
            }
            while (carry > 0) {
                int s = int(res[k]-'0') + carry;
                res[k++] = char(s%10 + '0');
                carry = s/10;
            }
        }
        while (!res.empty() && res.back() == '0') res.pop_back();
        return res;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res;
        if (num1.size() < num2.size()) res = mul(num2, num1);
        else res = mul(num1, num2);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a = "99999999999999999999999999999";
    string b = "99999999999999999999999999999";
    Solution s;
    string r = s.multiply(a, b);
    cout << r << endl;
    return 0;
}