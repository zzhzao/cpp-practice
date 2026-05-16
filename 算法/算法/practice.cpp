class Solution {
public:


    void  quicksort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int key = getRandom(nums, left, right);
        int i = left, l = left - 1, r = right + 1;
        while (i < r)
        {
            if (nums[i] < key)
            {
                swap(nums[i++], nums[++l]);
            }
            else if (nums[i] == key)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[--r]);
            }
        }
        quicksort(nums, left, l);
        quicksort(nums, r, right);
    }
    int getRandom(vector<int>& nums, int left, int right)
    {
        int r = rand();
        return nums[r % (right - left + 1) + left];
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
