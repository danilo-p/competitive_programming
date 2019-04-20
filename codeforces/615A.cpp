#include <bits/stdc++.h>

#define MAX_M 100

using namespace std;

int main() {
    int n, m, i, l, j, x;

    cin >> n >> m;

    bool m_on[MAX_M];
    for (i = 0; i < m; i++)
        m_on[i] = false;

    for (i = 0; i < n; i++) {
        cin >> x;
        for (j = 0; j < x; j++) {
            cin >> l;
            m_on[l - 1] = true;
        }
    }

    bool yes = true;
    for (i = 0; i < m; i++)
        if (!m_on[i])
            yes = false;

    if (yes) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}