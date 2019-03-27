#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int union_find[MAX_N];

int uf_find(int x) {
    if (union_find[x] == x) return x;
    return uf_find(union_find[x]);
}

void uf_union(int x, int y) {
    int parent_x = uf_find(x), parent_y = uf_find(y);
    union_find[parent_x] = parent_y;
}

void uf_normalize(int n) {
    int i, parent;
    for (i = 0; i < n; i++) {
        parent = uf_find(i);
        union_find[i] = parent;
    }
}

void uf_reset(int n) {
    for (int i = 0; i < n; i++)
        union_find[i] = i;
}

int main() {
    int n, m, i, s1, s2, count, cases;

    cases = 0;
    cin >> n >> m;
    while (n && m) {
        uf_reset(n);

        for (i = 0; i < m; i++) {
            cin >> s1 >> s2;
            uf_union(s1 - 1, s2 - 1);
        }

        uf_normalize(n);
        sort(union_find, union_find + n);

        count = 1;
        for (i = 1; i < n; i++)
            if (union_find[i - 1] != union_find[i])
                count++;

        cases++;
        cout << "Case " << cases << ": " << count << endl;

        cin >> n >> m;
    }

    return 0;
}