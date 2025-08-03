#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};

