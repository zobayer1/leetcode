#include <string>

using namespace std;

/* 12. Integer to Roman */

class Solution {
public:
    string intToRoman(int num) {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman = "";
        for (int i = 0; num > 0; ++i) {
            int m = num / val[i];
            for(int k = 0; k < m; ++k) roman += rom[i];
            num -= m * val[i];
        }
        return roman;
    }
};
