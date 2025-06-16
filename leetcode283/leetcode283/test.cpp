#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1;
        int cur = 0;
        while (cur < nums.size())
        {
            if (nums[cur] != 0)
            {
                dest++;
                swap(nums[dest], nums[cur]);
            }
            cur++;
        }
    }
};