//#define _CRT_SECURE_NO_WARNINGS 1
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int n = arr.size();
//        int top = 0;
//        int i = -1;
//        while (top < n) {
//            i++;
//            if (arr[i] != 0) {
//                top++;
//            }
//            else {
//                top += 2;
//            }
//        }
//        int j = n - 1;
//        if (top == n + 1) {
//            arr[j] = 0;
//            j--;
//            i--;
//        }
//        while (j >= 0) {
//            arr[j] = arr[i];
//            j--;
//            if (!arr[i]) {
//                arr[j] = arr[i];
//                j--;
//            }
//            i--;
//        }
//    }
//};
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0;
        int dest = -1;
        int n = arr.size();
        while (cur < n)
        {
            if (arr[cur])
                dest++;
            else
                dest += 2;
            if (dest >= n - 1)
                break;
            cur++;
        }
        if (dest == n)
        {
            arr[n - 1] = 0;
            dest -= 2;
            cur--;
        }
        while (cur >= 0)
        {
            if (arr[cur])
            {
                arr[dest--] = arr[cur];
            }
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
            }
            cur--;
        }
    }
};