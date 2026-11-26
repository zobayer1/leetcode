#include <string>

using namespace std;

/* 58. Length of Last Word */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = (int) s.size();
        int i, cnt;
        for (i = 0; i < n; i++) if (s[n-i-1] != ' ') break;
        n = n - i;
        for (i = cnt = 0; i < n; i++) {
            if (s[n-i-1] == ' ') break;
            cnt++;
        }
        return cnt;
    }
};
