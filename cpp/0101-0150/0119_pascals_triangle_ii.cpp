#include <vector>

using namespace std;

/* 119. Pascal's Triangle II */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector< int > row;
        row.resize(rowIndex + 1);
        row[0] = 1;
        for (int k = 1; k <= rowIndex; k++) row[k] = int((long long)row[k-1] * (rowIndex - k + 1) / k);
        return row;
    }
};

