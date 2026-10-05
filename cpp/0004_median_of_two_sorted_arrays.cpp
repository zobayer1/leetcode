#include <vector>

using namespace std;


/* 4. Median of Two Sorted Arrays */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = static_cast<int>(nums1.size());
        int n2 = static_cast<int>(nums2.size());
        int mid = (n1 + n2) >> 1, odd = (n1 + n2) & 1;
        int val, sum = 0;
        
        for (int i = 0, j = 0, k = 0; i < n1 || j < n2; k++) {
            if (i == n1) val = nums2[j++];
            else if (j == n2) val = nums1[i++];
            else if (nums1[i] < nums2[j]) val = nums1[i++];
            else val = nums2[j++];
            if (k == mid - 1 && !odd) sum += val;
            if (k == mid) {
                sum += val;
                break;
            }
        }

        if (odd) return (double) sum;
        return 0.5 * sum;
    }
};
