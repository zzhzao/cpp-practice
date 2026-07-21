#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> cnt; // 统计每种声部的人数 

bool check(int x) // 判断最多人数为 x 时，能否分成 m 组 
{
    int g = 0; // 能分成多少组 
    for (auto& [a, b] : cnt)
    {
        g += b / x + (b % x == 0 ? 0 : 1);
    }
    return g <= m;
}

int main()
{
    cin >> n >> m;
    int hmax = 0; // 统计声部最多的人数 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hmax = max(hmax, ++cnt[x]);
    }

    int kinds = cnt.size();
    if (kinds > m) // 处理边界情况 
    {
        cout << -1 << endl;
    }
    else
    {
        // 二分法
        int l = 1, r = hmax;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}