class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, len = 0;
        for (int i = 0;i < n;i++)
        {
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }
        return s.substr(begin, len);
    }
};