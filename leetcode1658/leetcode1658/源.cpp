class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int a : nums) sum += a;
        int target = sum - x;
        if (target < 0) return -1;
        int ret = -1;
        for (int left = 0, right = 0, tmp = 0;right < nums.size();right++)
        {
            tmp += nums[right];
            while (tmp > target)
                tmp -= nums[left++];
            if (target == tmp)
                ret = max(right - left + 1, ret);
        }
        if (ret == -1) return -1;
        else return nums.size() - ret;
    }
};