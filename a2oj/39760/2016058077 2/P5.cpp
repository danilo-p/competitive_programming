#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

int n;
int arr[MAX_N];
pair<int, int> st[5 * MAX_N];
pair<int, int> null_pair = make_pair(INT_MIN, INT_MAX);

pair<int, int> st_query(int si, int ss, int se, int qs, int qe)
{
  if (qs <= ss && se <= qe)
    return st[si];

  if (se < qs || ss > qe)
    return null_pair;

  int m = (ss + se) / 2;

  pair<int, int> rl = st_query(2 * si + 1, ss, m, qs, qe);
  pair<int, int> rr = st_query(2 * si + 2, m + 1, se, qs, qe);

  return make_pair(max(rl.first, rr.first), min(rl.second, rr.second));
}

void st_update(int si, int ss, int se, int i, int v)
{
  if (ss == se) {
    st[si].first = v;
    st[si].second = v;
    return;
  }

  int m = (ss + se) / 2;
  if (ss <= i && i <= m) {
    st_update(2 * si + 1, ss, m, i, v);
  } else {
    st_update(2 * si + 2, m + 1, se, i, v);
  }

  pair<int, int> rl = st[2 * si + 1];
  pair<int, int> rr = st[2 * si + 2];

  st[si].first = max(rl.first, rr.first);
  st[si].second = min(rl.second, rr.second);
}

pair<int, int> st_build(int si, int ss, int se)
{
  if (ss == se)
  {
    st[si].first = arr[ss];
    st[si].second = arr[ss];
    return st[si];
  }

  int m = (ss + se) / 2;

  pair<int, int> rl = st_build(si * 2 + 1, ss, m);
  pair<int, int> rr = st_build(si * 2 + 2, m + 1, se);

  st[si].first = max(rl.first, rr.first);
  st[si].second = min(rl.second, rr.second);

  return st[si];
}

int main()
{
  std::ios::sync_with_stdio(false);
  while (cin >> n)
  {
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    st_build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
      int k, i, j, p;
      pair<int, int> res;
      cin >> k >> i;
      if (k == 1)
      {
        cin >> p;
        st_update(0, 0, n - 1, i - 1, p);
      }
      else
      {
        cin >> j;
        res = st_query(0, 0, n - 1, i - 1, j - 1);
        cout << res.first - res.second << endl;
      }
    }
  }
  return 0;
}
