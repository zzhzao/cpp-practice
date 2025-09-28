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
//复写零

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int src = 0;
        int dest = 0;
        vector<int> v;
        v.reserve(arr.size());
        while (dest < arr.size())
        {
            if (arr[src] == 0)
            {
                v[dest++] = 0;
                if (dest < arr.size())
                    v[dest++] = 0;
            }
            else
            {
                v[dest++] = arr[src];
            }
            src++;
        }
        for (int i = 0;i < arr.size();i++)
        {
            arr[i] = v[i];
        }
    }
};


///////////
class Solution{
public:
    void duplicateZeros(vector<int>&arr) {
        int cur = 0;
        int dest = 0;
        int n = arr.size();
        while (cur < n)
        {
            if (arr[cur])
                dest++;
            else
                dest += 2;
            if (dest >= n)
            {
                dest--;
                break;
            }
            cur++;
        }
        if (dest == n)
        {
            dest = n - 2;
            cur--;
            arr[n - 1] = 0;
        }
        while (cur >= 0)
        {
            if (arr[cur]) arr[dest--] = arr[cur--];
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};