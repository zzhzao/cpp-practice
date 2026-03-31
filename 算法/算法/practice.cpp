#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    cout << dp[n] << endl;
    return 0;
}