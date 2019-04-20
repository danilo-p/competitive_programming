#include <bits/stdc++.h>

using namespace std;

int main() {
    int value, n;
    cin >> value >> n;
    int dp[value + 1], V[n], i, j, ans;
    memset(dp, 0, sizeof dp);
    for (i = 0; i < n; i++)
        cin >> V[i];
    for (i = 1; i <= value; i++) {
        ans = INT_MAX;
        for (j = 0; j < n; j++)
            if (i - V[j] >= 0)
                ans = min(ans, 1 + dp[i - V[j]]);
        dp[i] = ans;
    }
    cout << dp[value] << endl;
    return 0;
}