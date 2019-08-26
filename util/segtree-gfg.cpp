#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

int arr[MAX_N];
int st[5 * MAX_N];

int st_query(int si, int ss, int se, int qs, int qe)
{
  if (qs <= ss && qe >= se)
    return st[si];

  if (se < qs || ss > qe)
    return 0;

  int m = ss + (se - ss) / 2;
  return st_query(2 * si + 1, ss, m, qs, qe) +
         st_query(2 * si + 2, m + 1, se, qs, qe);
}

void st_update(int si, int ss, int se, int i, int diff)
{
  if (i < ss || i > se)
    return;

  st[si] = st[si] + diff;
  if (se != ss)
  {
    int m = ss + (se - ss) / 2;
    st_update(2 * si + 1, ss, m, i, diff);
    st_update(2 * si + 2, m + 1, se, i, diff);
  }
}

int st_build(int si, int ss, int se)
{
  if (ss == se)
  {
    st[si] = arr[ss];
    return arr[ss];
  }

  int m = ss + (se - ss) / 2;
  st[si] = st_build(si * 2 + 1, ss, m) +
           st_build(si * 2 + 2, m + 1, se);
  return st[si];
}

int main()
{
  return 0;
}
