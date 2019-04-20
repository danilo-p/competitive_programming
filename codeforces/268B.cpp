#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, c = 0;

    cin >> n;

    for (i = 1; i < n; i++)
        c += (n - i) * i;
    c += n;

    cout << c << endl;

    return 0;
}