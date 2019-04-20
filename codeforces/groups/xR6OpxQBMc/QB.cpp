#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, sum = 0, a;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }
    printf("%.7f", (double) sum / n);
    return 0;
}