#include <vector>

using namespace std;

/* 36. Valid Sudoku */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int lcnt[9][10] = {0};
        int rcnt[9][10] = {0};
        int scnt[9][10] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int val = int(board[i][j] - '0');
                if (rcnt[i][val] > 0) return false;
                rcnt[i][val]++;
                if (lcnt[j][val] > 0) return false;
                lcnt[j][val]++;
                int s = (i/3) * 3 + (j/3);
                if (scnt[s][val] > 0) return false;
                scnt[s][val]++;
            }
        }
        return true;
    }
};
