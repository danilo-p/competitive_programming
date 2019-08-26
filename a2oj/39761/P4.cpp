#include "bits/stdc++.h"

using namespace std;

#define MAX_SIZE_N 100000

typedef long long ll;

vector<ll> v((MAX_SIZE_N + 1), 0);
vector<ll> segtree(4 * (MAX_SIZE_N + 1), 0);

ll segtree_build(ll id, ll left, ll right) {
    if (left == right) {
        segtree[id] = v[left];
        return v[left];
    }
    ll m = (left + right) / 2;
    ll ml = segtree_build(2 * id, left, m);
    ll mr = segtree_build(2 * id + 1, m + 1, right);
    return segtree[id] = ml + mr;
}

pair<int,int> segtree_query(int id, int tl, int tr, int ql, int qr) { // tl <= ql <= qr <= tr
    cout << "segtree_query " << id << " " << tl << " " << tr << " " << ql << " " << qr << endl;
    if (id == 0) {
        exit(1);
    }
    if (tl == ql && qr == tr) {
        return make_pair(segtree[id], 1);
    }
    int m = (tl + tr) / 2;
    if (tr <= m) {
        return segtree_query(2 * id, tl, m, ql, qr);
    }
    if (tl >= m + 1) {
        return segtree_query(2 * id + 1, m + 1, tr, ql, qr);
    }
    return max(segtree_query(2 * id, tl, m, ql, m), segtree_query(2 * id + 1, m + 1, tr, m + 1, qr));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << "debug" << endl;
        ll n;
        cin >> n;
        cout << "debug" << endl;
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        segtree_build(1, 1, n);
        cout << "debug" << endl;
        ll q, i, j;
        cin >> q;
        for (ll i = 0; i < q; i++) {
            cin >> i >> j;
            cout << "debug " << i << j << endl;
            pair<int, int> solution = segtree_query(1, 1, n, i, j);
            cout << "debug " << i << j << endl;
            cout << solution.first << " " << solution.second << endl;
        }
    }
    return 0;
}