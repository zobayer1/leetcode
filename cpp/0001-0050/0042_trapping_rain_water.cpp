#include <algorithm>
#include <vector>

using namespace std;

/* 42. Trapping Rain Water */

class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft = 0, maxright = 0;
        int left = 0, right = height.size() - 1;
        int total = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                maxleft = max(maxleft, height[left]);
                total += maxleft - height[left];
                left++;
            } else {
                maxright = max(maxright, height[right]);
                total += maxright - height[right];
                right--;
            }
        }
        return total;
    }
};
