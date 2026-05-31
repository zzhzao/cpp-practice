class Solution {
public:
        string removeDuplicates(string s) {
            string ret;
            for (auto e : s)
            {
                if (!ret.empty() && e == ret.back())
                {
                    ret.pop_back();
                }
                else
                {
                    ret.push_back(e);
                }
            }
            return ret;
        }
    };