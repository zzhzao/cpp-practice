class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        int n = s.size();
        int i = 0;
        char op = '+';
        while (i < n) {
            int tmp = 0;
            if (s[i] == ' ')
                i++;
            else if (s[i] >= '0' && s[i] <= '9') {
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    tmp = tmp * 10 + (s[i++] - '0');
                }
                if (op == '+') {
                    stack.push_back(tmp);
                }
                else if (op == '-') {
                    stack.push_back(-tmp);
                }
                else if (op == '*') {
                    stack.back() *= tmp;
                }
                else {
                    stack.back() /= tmp;
                }
            }
            else {
                op = s[i];
                i++;
            }
        }
        int ret = 0;
        for (auto e : stack) {
            ret += e;
        }
        return ret;
    }
};