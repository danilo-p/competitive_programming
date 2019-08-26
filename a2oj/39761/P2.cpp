#include "bits/stdc++.h"

using namespace std;

bool valid(int l1, int l2, int l3) {
    return (
        l1 + l2 > l3
        && l3 + l2 > l1
        && l3 + l1 > l2
    );
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (i + j valid(s[i], s[j], s[k])) {
                    cout << "YES" << endl;
                    return 0;
                }
    cout << "NO" << endl;
    return 0;
}