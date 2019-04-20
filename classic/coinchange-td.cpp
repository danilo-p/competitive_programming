#include <bits/stdc++.h>

#define MAX_VALUE 100
#define MAX_COINS 100

using namespace std;

int memo[MAX_VALUE], n, V[MAX_COINS];

int cc(int value) {
    if (memo[value] != -1)
        return memo[value];

    int ans = INT_MAX, i;

    if (value == 0)
        ans = 0;
    else if (value < 0)
        return INT_MAX;
    else
        for (i = 0; i < n; i++)
            ans = min(ans, 1 + cc(value - V[i]));

    memo[value] = ans;
    return ans;
}

int main() {
    int i, v;
    cin >> v >> n;
    memset(memo, -1, sizeof memo);
    for (i = 0; i < n; i++)
        cin >> V[i];
    cout << cc(v) << endl;
    return 0;
}