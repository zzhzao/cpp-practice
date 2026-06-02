class Solution {
public:
    string decodeString(string s) {
        vector<int> nums;
        vector<string> strs;
        int i = 0;
        int n = s.size();
        while (i < n)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    tmp = tmp * 10 + (s[i] - '0');
                    i++;
                }
                nums.push_back(tmp);
            }
            else if (s[i] == '[')
            {
                strs.push_back("");
                i++;

            }
            else if (s[i] == ']')
            {
                int k = nums.back();
                nums.pop_back();
                string tmp;
                while (k--)
                {
                    tmp += strs.back();
                }
                strs.pop_back();
                if (!strs.empty()) {
                    strs.back() += tmp;
                }
                else {
                    strs.push_back(tmp);
                }
                i++;
            }
            else
            {
                string str;
                while (i < n && s[i] >= 'a' && s[i] <= 'z')
                {
                    str += s[i++];
                }
                if (!strs.empty()) strs.back() += str;
                else strs.push_back(str);
            }
        }
        return strs[0];
    }
};