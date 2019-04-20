#include <bits/stdc++.h>

#define MAX_N 10

using namespace std;

int n, dist[MAX_N][MAX_N], memo[MAX_N][1 << MAX_N];

int tsp(int pos, long long int visited) {
    if (visited == (1 << n) - 1)
        return dist[pos][0];
    if (memo[pos][visited] != -1)
        return memo[pos][visited];
    int ans = INT_MAX, i;
    for (i = 0; i < n; i++)
        if (i != pos && !(visited & (1 << i)))
            ans = min(ans, dist[pos][i] + tsp(i, visited | (1 << i)));
    memo[pos][visited] = ans;
    return ans;
}

int main() {
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> dist[i][j];
    memset(memo, -1, sizeof memo);
    cout << tsp(0, 1) << endl;
    return 0;
}