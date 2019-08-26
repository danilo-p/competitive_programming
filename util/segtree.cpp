#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

typedef struct {
  int sum;
  int min;
  int max;
} t_st_node;
int arr[MAX_N];
t_st_node st[5 * MAX_N];

t_st_node st_build_node(int min, int max) {
  t_st_node new_node;
  new_node.min = min;
  new_node.max = max;
  return new_node;
}

void st_node_assign(t_st_node *dest, int min, int max) {
  dest->min = min;
  dest->max = max;
}

void st_operate(t_st_node *dest, t_st_node a, t_st_node b) {
  st_node_assign(dest, min(a.min, b.min), max(a.max, b.max));
}

void st_operate_const(t_st_node *dest, int k) {
  st_node_assign(dest, dest->min + k, dest->max + k);
}

void st_update(int si, int sl, int sr, int ui, int x) {
  if (sl == sr) {
    st_operate_const(&st[si], x);
    return;
  }
  int m = (sr + sl) / 2;
  if (ui <= m)
    st_update(2 * si + 1, sl, m, ui, x);
  else if (ui >= m + 1)
    st_update(2 * si + 2, m + 1, ui, ui, x);
  st_operate(&st[si], st[2 * si + 1], st[2 * si + 2]);
}

t_st_node st_query(int si, int al, int ar, int ql, int qr) {
  if (ar < ql || al > qr) return st_build_node(INT_MAX, INT_MIN);
  if (ql <= al && qr >= ar) return st[si];
  int m = (al + ar) / 2;
  t_st_node res = st_build_node(INT_MAX, INT_MIN);
  st_operate(&res, st_query(2 * si + 1, al, m, ql, qr), st_query(2 * si + 2, m + 1, ar, ql, qr));
  return res;
}

t_st_node st_build(int si, int al, int ar) {
  if (al == ar) {
    st_node_assign(&st[si], arr[al], arr[al]);
    return st[si];
  }
  int m = (al + ar) / 2;
  st_operate(&st[si], st_build(si * 2 + 1, al, m), st_build(si * 2 + 2, m + 1, ar));
  return st[si];
}

void st_reset(int n) {
  for (int i = 0; i < 5 * n; i++)
    st_node_assign(&st[i], INT_MAX, INT_MIN);
}

int main() {
  int n, q, i, j, k, l;
  t_st_node res;
  while (cin >> n) {
    for (i = 0; i < n; i++) cin >> arr[i];
    st_reset(n);
    st_build(0, 0, n - 1);
    cin >> q;
    for (i = 0; i < q; i++) {
      cin >> k >> j >> l;
      switch (k) {
        case 1:
          st_update(0, 0, n - 1, j - 1, l - arr[j - 1]);
          break;
        case 2:
          res = st_query(0, 0, n - 1, j - 1, l - 1);
          cout << res.max - res.min << endl;
          break;
      }
    }
  }
  return 0;
}