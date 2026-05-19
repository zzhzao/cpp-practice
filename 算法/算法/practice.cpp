class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0;i < nums.size();i++)
        {
            auto it = hash.find(nums[i]);
            if (it != hash.end())
            {
                if ((i - it->second) <= k)
                {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};