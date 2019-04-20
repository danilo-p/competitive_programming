#include <bits/stdc++.h>

using namespace std;

typedef long long int lli_t;
typedef pair< lli_t, pair<lli_t, lli_t> > pos_t;

int main() {
    set< pos_t > rank;
    lli_t n, id, prob, pen, i, pos;
    pos_t last;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> id >> prob >> pen;
        rank.insert(make_pair(-prob, make_pair(pen, id)));
    }

    i = 1;
    pos = 1;
    bool first_loop = true;
    for (auto c : rank) {
        if (first_loop) {
            last = c;
            first_loop = false;
        }

        if (c.first != last.first || c.second.first != last.second.first) {
            pos = i;
        }

        cout << pos << " " << c.second.second << " " << (-c.first) << " " << (c.second.first) << endl;

        last = c;
        i++;
    }

    return 0;
}