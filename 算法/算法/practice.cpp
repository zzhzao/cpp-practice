class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
        {
            return false;
        }
        int hash1[26] = { 0 };
        int hash2[26] = { 0 };
        int target = 0;
        for (auto e : s1)
        {
            hash1[e - 'a']++;
            target++;
        }
        int count = 0;
        for (auto e : s2)
        {
            if (hash2[e - 'a'] < hash1[e - 'a'])
            {
                count++;
            }
            hash2[e - 'a']++;
        }
        if (target == count)
        {
            return true;
        }
        return false;
    }
};