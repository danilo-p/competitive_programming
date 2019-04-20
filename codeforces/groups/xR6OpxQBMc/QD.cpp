#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, i, j, c, c2;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    c = 1;
    for (i = 0; i < n; i++) {
        c2 = c;

        for (j = 0; j < 25; j++)  {
            c += c2;
            c = c % ((long long int) (1e9 + 7));
        }
    }

    if (n >= 16)
        c--;

    cout << c;

    return 0;
}