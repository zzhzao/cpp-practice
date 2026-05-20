class Solution {
public:
    string addBinary(string a, string b) {
        int cur1 = a.size() - 1;
        int cur2 = b.size() - 1;
        int count = 0;
        string ret;
        while (cur1 >= 0 || cur2 >= 0 || count > 0)
        {
            if (cur1 >= 0) count += a[cur1--] - '0';
            if (cur2 >= 0) count += b[cur2--] - '0';

            if (count % 2 == 0)
            {
                ret += '0';
            }
            else
            {
                ret += '1';
            }
            count /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};