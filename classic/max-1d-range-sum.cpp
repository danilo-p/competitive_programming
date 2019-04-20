#include <bits/stdc++.h>

#define MAX_N 1000

using namespace std;

int main() {
    int i, j, k, n, a[MAX_N], b[MAX_N], ans, sum;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    
    // Complete search O(n^3)
    ans = INT_MIN;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = i; k <= j; k++)
                sum += a[k];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

    // DP strategy O(n^2)
    b[0] = a[0];
    for (i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    ans = INT_MIN;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            ans = max(ans, b[j] - (i == 0 ? 0 : b[i - 1]));
    cout << ans << endl;

    // Jay Kadane O(n)
    sum = 0;
    ans = INT_MIN;
    for (i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << ans << endl;

    return 0;
}