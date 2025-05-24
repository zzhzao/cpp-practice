#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for (int i = 0; i < vv.size(); i++)
        {
            vv[i].resize(i + 1, 1);
        }
        for (int i = 2; i < vv.size();i++)
        {
            for (int j = 1; j < vv[i].size() - 1;j++)
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> triangle = sol.generate(5);
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}