#include <string>
#include <vector>

using namespace std;

/* 68. Text Justification */

class Solution {
    string concatJustified(vector< string >& words, int start, int end, int total, int maxWidth) {
        int nwords = end - start;
        if (nwords == 1) return concatLeft(words, start, end, maxWidth);
        string res = "";
        res.reserve(maxWidth);
        total -= nwords;
        int spaces = maxWidth - total;
        int minSpaces = spaces / (nwords - 1);
        int extraSpaces = spaces % (nwords - 1);
        res += words[start];
        for (int i = start + 1; i < end; i++) {
            int spaceCount = minSpaces + (extraSpaces-- > 0 ? 1 : 0);
            res.append(spaceCount, ' ');
            res += words[i];
        }
        return res;
    }
    string concatLeft(vector< string >& words, int start, int end, int maxWidth) {
        string res;
        res.reserve(maxWidth);
        res += words[start];
        for (int i = start + 1; i < end; i++) {
            res.push_back(' ');
            res += words[i];
        }
        res.append(maxWidth - res.size(), ' ');
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int length = 0, start = 0;
        vector< string> res;
        for (int i = 0; i < words.size(); i++) {
            int wlen = words[i].size() + 1;
            length += wlen;
            if (length > maxWidth + 1) {
                res.push_back(concatJustified(words, start, i, length-wlen, maxWidth));
                length = wlen;
                start = i;
            }
        }
        if (length > 0) res.push_back(concatLeft(words, start, words.size(), maxWidth));
        return res;
    }
};
