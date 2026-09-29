class Solution {
public:
    int numberOfSpecialChars(string word) {
        int up[26] = {}, lo[26] = {};
        for (char ch: word) {
            if (std::isupper(ch)) up[ch - 'A'] = 1;
            else if (std::islower(ch)) lo[ch - 'a'] = 1;
        }
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            ret += ((up[i] & lo[i]) > 0);
        }
        return ret;
    }
};

