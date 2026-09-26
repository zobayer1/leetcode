class Solution {
public:
    int myAtoi(string s) {
        size_t start = s.find_first_not_of(' ');
        if (start == std::string::npos) {
            return 0;
        }
        int neg = 0;
        if (s[start] == '-') {
            neg = 1;
            start++;
        } else if (s[start] == '+') start++;
        long long num = 0, cap = (long long)INT_MAX + neg;
        for (; start < s.length(); start++) {
            if (s[start] < '0' || s[start] > '9') break;
            num = num * 10 + s[start] - '0';
            if (num > cap) { num = cap; break; }
        }
        if (neg) num = -num;
        return (int)num;
    }
};

