#include <bits/stdc++.h>

#define ASCII_0 48

using namespace std;

int main() {
    int k, i, k2;
    multiset<int> n_ord;
    string n;
    cin >> k >> n;
    k2 = 0;

    for (i = 0; i < n.size(); i++)  {
        k2 += (n[i] - ASCII_0);
        n_ord.insert(n[i] - ASCII_0);
    }

    if (k <= k2) {
        cout << 0 << endl;
        return 0;
    }

    int c = 0, d = k - k2;
    for (auto a : n_ord) {
        d -= (9 - a);
        c++;
        if (d <= 0) {
            break;
        }
    }
    cout << c << endl;
    return 0;
}