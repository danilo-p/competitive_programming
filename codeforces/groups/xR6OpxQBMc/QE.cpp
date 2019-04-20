#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, a, b, c = 0;
    vector<pair<int, int> > vhs;
    pair<int, int> curr;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a >> b;
        a--;
        vhs.push_back(make_pair(a, b));
    }

    for (i = 0; i < n; i++) {
        auto it = vhs.begin();
        for (j = 0; j < n; j++) {
            if (vhs[j].first == i)
                break;
        }

        for (; j < n; j++) {
            c += vhs[j].second;
        }

        curr = vhs.at(j);
        vhs.erase(vhs.at(j));
        vhs.push_back(curr);
    }

    cout << c << endl;

    return 0;
}