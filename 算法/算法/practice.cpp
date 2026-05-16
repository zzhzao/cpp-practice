class Solution {
    vector<int> ret = { 0 };
    vector<int> index;
    int tmp[500010];
    int tmpindex[500010];
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ret.resize(n);

        index.resize(n);

        for (int i = 0; i < n; i++)
            index[i] = i;

        mergeSort(nums, 0, nums.size() - 1);
        return ret;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = (right - left) / 2 + left;

        int cur1 = left, cur2 = mid + 1, i = 0;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] > nums[cur2])
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmpindex[i] = index[cur1];
                tmp[i++] = nums[cur1++];
            }
            else
            {
                tmpindex[i] = index[cur2];
                tmp[i++] = nums[cur2++];
            }
        }
        while (cur1 <= mid)
        {
            tmpindex[i] = index[cur1];
            tmp[i++] = nums[cur1++];
        }
        while (cur2 <= right)
        {
            tmpindex[i] = index[cur2];
            tmp[i++] = nums[cur2++];
        }
        for (int j = left;j <= right;j++)
        {
            nums[j] = tmp[j - left];
            index[j] = tmpindex[j - left];
        }
    }

};