class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> sv(numRows, "");
        string result;
        result.reserve(s.length());
        int row = 0, rd = 1;
        for (int i = 0; i < s.length(); i++) {
            sv[row] += s[i];
            if (row + rd == numRows) {
                rd *= -1;
            }
            if (row + rd < 0) {
                rd *= -1;
            }
            if (numRows > 1) row += rd;
        }
        for (string sr: sv) result += sr;
        return result;
    }
};
