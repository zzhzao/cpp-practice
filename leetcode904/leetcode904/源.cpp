class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int hash[100001] = { 0 };
        int ret = 0;
        for (int left = 0, right = 0, kinds = 0;right < fruits.size();right++)
        {
            if (hash[fruits[right]] == 0) kinds++;
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0) kinds--;
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};