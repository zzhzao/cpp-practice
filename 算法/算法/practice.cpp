class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for (auto e : s)
        {
            if (!s1.empty() && e == '#')
            {
                s1.pop_back();
            }
            else if (e != '#')
            {
                s1.push_back(e);
            }
        }
        for (auto e : t)
        {
            if (!s2.empty() && e == '#')
            {
                s2.pop_back();
            }
            else if (e != '#')
            {
                s2.push_back(e);
            }
        }
        if (s1 == s2)
        {
            return true;
        }
        return false;

    }
};