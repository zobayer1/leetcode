#include <vector>

using namespace std;

/* 88. Merge Sorted Array */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector< int > merged;
        merged.reserve(m+n);
        int i, j;
        for (i = j = 0; i < m && j < n;) {
            if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        for (; i < m; i++) merged.push_back(nums1[i]);
        for (; j < n; j++) merged.push_back(nums2[j]);
        nums1 = merged;
    }
};
