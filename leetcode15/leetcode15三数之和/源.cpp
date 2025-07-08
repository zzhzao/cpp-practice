class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n - 2;)
        {
            if (nums[i] > 0)
                break;
            int left = i + 1, right = n - 1, target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                    right--;
                else if (nums[left] + nums[right] < target)
                    left++;
                else
                {
                    ret.push_back({ nums[i],nums[left],nums[right] });
                    left++;right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1])  right--;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return ret;
    }
};