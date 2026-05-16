class Solution {
    int tmp[50010];
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
    int mergesort(vector<int>& nums, int left, int right)
    {
        int ret = 0;
        if (left >= right)
        {
            return 0;
        }
        int mid = (right - left) / 2 + left;
        int cur1 = left, cur2 = mid + 1, i = 0;
        ret += mergesort(nums, left, mid);
        ret += mergesort(nums, mid + 1, right);

        while (cur1 <= mid)
        {
            for (;cur2 <= right;cur2++)
            {
                if (nums[cur1] / 2.0 > nums[cur2])
                {
                    ret += right - cur2 + 1;
                    break;
                }
            }
            cur1++;
        }

        cur1 = left, cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] > nums[cur2])
            {
                tmp[i++] = nums[cur1++];
            }
            else
            {
                tmp[i++] = nums[cur2++];
            }
        }
        while (cur1 <= mid)    tmp[i++] = nums[cur1++];
        while (cur2 <= right)      tmp[i++] = nums[cur2++];

        for (int j = left; j <= right; j++)
            nums[j] = tmp[j - left];
        return ret;
    }
};