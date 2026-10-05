#include <string>

using namespace std;

/* 3. Longest Substring Without Repeating Characters */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_seen[128] = {0};
        int left = 0;
        int maxlen = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (last_seen[c] > left) {
                left = last_seen[c];
            }
            last_seen[c] = right+1;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
