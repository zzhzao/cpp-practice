#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid;
        }
        return right;
    }
};
