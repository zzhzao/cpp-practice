class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return { -1,-1 };
        }
        int left = 0, right = nums.size() - 1;
        int resleft = -1;
        int resright = -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target)
        {
            resleft = left;
        }
        left = 0;right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2 + 1;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        if (nums[right] == target)
        {
            resright = right;
        }
        return { resleft,resright };

    }
};