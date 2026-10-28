#include <vector>

using namespace std;

/* 59. Spiral Matrix II */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int minr = 0, minc = 0, maxr = n, maxc = n;
        int total = n * n;
        int delr = 0, delc = 1;
        vector< vector<int> > res;
        res.resize(n);
        for (int i = 0; i < n; i++) res[i].resize(n);
        for (int r = 0, c = 0, k = 0; k < total; k++) {
            res[r][c] = k+1;
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
