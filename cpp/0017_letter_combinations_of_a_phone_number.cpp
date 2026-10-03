class Solution {
    string keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        q.push("");
        for (int i = 0; i < digits.size(); ++i) {
            int idx = digits[i] - '0';
            while (q.front().size() < i + 1) {
                string tp = q.front(); q.pop();
                for (int j = 0; j < keys[idx].size(); ++j) q.push(tp + string(1, keys[idx][j]));
            }
        }
        vector<string> result;
        result.reserve(q.size());
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
