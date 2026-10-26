#include <vector>

using namespace std;

/* 54. Spiral Matrix */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minr = 0, minc = 0, maxr = (int) matrix.size(), maxc = (int) matrix[0].size();
        int total = maxr * maxc;
        int delr = 0, delc = 1;
        vector< int > res;
        res.resize(total);
        for (int r = 0, c = 0, k = 0; k < total; k++) {
            res[k] = matrix[r][c];
            r += delr;
            c += delc;
            if (c == maxc) {
                minr++;
                r -= delr, c -= delc;
                delr = 1, delc = 0;
                r += delr, c += delc;
            } else if (r == maxr) {
                maxc--;
                r -= delr, c -= delc;
                delr = 0, delc = -1;
                r += delr, c += delc;
            } else if (c < minc) {
                maxr--;
                r -= delr, c -= delc;
                delr = -1, delc = 0;
                r += delr, c += delc;
            } else if (r < minr) {
                minc++;
                r -= delr, c -= delc;
                delr = 0, delc = 1;
                r += delr, c += delc;
            }
        }
        return res;
    }
};
