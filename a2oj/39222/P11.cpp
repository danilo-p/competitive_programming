#include <bits/stdc++.h>

#define MAX_N 1000

using namespace std;

int n, N[MAX_N], memo[MAX_N][MAX_N];

int EO(int i, int j) {
    if (i >= j) {
        return 0;
    }

    if (memo[i][j]) {
        return memo[i][j];
    }

    int max_score = INT_MIN;
    
    max_score = max(max_score, ((N[i] % 2 == 0) ? 1 : 0) + EO(i + 1, j - 1));
    max_score = max(max_score, ((N[i] % 2 == 0) ? 1 : 0) + EO(i + 2, j));
    max_score = max(max_score, ((N[j] % 2 == 0) ? 1 : 0) + EO(i + 1, j - 1));
    max_score = max(max_score, ((N[j] % 2 == 0) ? 1 : 0) + EO(i, j - 2));

    memo[i][j] = max_score;
    return max_score;
}

int main() {
    int i;
    cin >> n;
    while (n) {
        n = 2 * n;
        for (i = 0; i < n; i++)
            cin >> N[i];
        memset(memo, 0, sizeof memo);
        cout << EO(0, n - 1) << endl;
        cin >> n;
    }
    return 0;
}