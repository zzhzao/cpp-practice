#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == mid) left = mid + 1;
			else right = mid;
		}
		return nums[left] == left ? left + 1 : left;
	}
};