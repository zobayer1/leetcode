#include <vector>

using namespace std;

/* 136. Single Number */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int v: nums) num ^= v;
        return num;
    }
};
