#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int w[n], v[n], i, j, dp[n + 1][s + 1];
    for (i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    memset(dp, 0, sizeof dp);
    for (i = n - 1; i >= 0; i--)
        for (j = 1; j <= s; j++)
            if (w[i] > j)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = max(dp[i + 1][j], v[i] + dp[i + 1][j - w[i]]);
    cout << dp[0][s];
    return 0;
}