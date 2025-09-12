#define _CRT_SECURE_NO_WARNINGS 1

//移动零
//自己的思路
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            while (right < nums.size() && nums[left] != 0)
            {
                left++;
                right++;
            }
            while (right < nums.size() && nums[right] == 0)
            {
                ++right;
            }
            if (left != right && right < nums.size())
                swap(nums[left++], nums[right]);
        }
    }
};

//标准思路

class Solution
{

public:
    void moveZeroes(vector<int>& nums)
    {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
            if (nums[cur]) // 处理⾮零元素 
                swap(nums[++dest], nums[cur]);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////