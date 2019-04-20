#include <bits/stdc++.h>

#define MAX_N 1000
#define MAX_S 1000

using namespace std;

int n, s, w[MAX_N], v[MAX_N], i, j, memo[MAX_N][MAX_S];

int ks(int id, int remW) {
    if (id == n || remW == 0)
        return 0;

    if (memo[id][remW])
        return memo[id][remW];

    int ans;
    if (w[id] > remW)
        ans = ks(id + 1, remW);
    else
        ans = max(ks(id + 1, remW), v[id] + ks(id + 1, remW - w[id]));

    memo[id][remW] = ans;
    return ans;
}

int main() {
    cin >> n >> s;
    for (i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    memset(memo, 0, sizeof memo);
    cout << ks(0, s) << endl;
    return 0;
}