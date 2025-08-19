#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int j;
        while (n > 1) {
            string st;
            for (int i = 0;i < s.size();++i) {
                j = i;
                while (j + 1 < s.size() && s[j] == s[j + 1]) {
                    ++j;
                }
                st += to_string(j - i + 1) + s[i];
                i = j;
            }
            s = st;
            --n;
        }
        return s;
    }
};
