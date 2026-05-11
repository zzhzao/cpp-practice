class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0;i < nums.size();i++)
        {
            for (int j = 0;j < nums.size() - i;j++)
            {
                if (j != nums.size() - 1 && nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};