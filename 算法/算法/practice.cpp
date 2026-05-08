class Solution {
public:
    bool isUnique(string astr) {
        int hash[26] = { 0 };
        for (auto e : astr)
        {
            if (hash[e - 'a'] == 0)
            {
                hash[e - 'a']++;
            }
            else if (hash[e - 'a'] == 1)
            {
                return false;
            }
        }
        return true;
    }
};