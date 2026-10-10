#include <string>

using namespace std;

/* 28. Find the Index of the First Occurrence in a String */

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != std::string::npos) {
            return (int) found;
        }
        return -1;
    }
};
