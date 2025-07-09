#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    int sum = nums[right] + nums[left];
                    long long aim = (long long)target - nums[i] - nums[j];
                    if (sum < aim)
                        left++;
                    else if (sum > aim)
                        right--;
                    else
                    {
                        ret.push_back({ nums[i],nums[j],nums[left++],nums[right--] });
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};