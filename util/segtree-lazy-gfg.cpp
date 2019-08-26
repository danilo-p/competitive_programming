#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10000;

int n;
int st[4 * MAX_N];
int st_lazy[4 * MAX_N];
int arr[MAX_N];

void st_propagate(int ss, int se, int si)
{
  if (st_lazy[si] != 0)
  {
    st[si] += st_lazy[si];

    if (ss != se)
    {
      st_lazy[si * 2 + 1] += st_lazy[si];
      st_lazy[si * 2 + 2] += st_lazy[si];
    }

    st_lazy[si] = 0;
  }
}

void st_update(int si, int ss, int se, int us,
               int ue, int diff)
{
  st_propagate(ss, se, si);

  if (ss > se || ss > ue || se < us)
    return;

  if (ss >= us && se <= ue)
  {
    st[si] += diff;

    if (ss != se)
    {
      st_lazy[si * 2 + 1] += diff;
      st_lazy[si * 2 + 2] += diff;
    }
    return;
  }

  int mid = (ss + se) / 2;
  st_update(si * 2 + 1, ss, mid, us, ue, diff);
  st_update(si * 2 + 2, mid + 1, se, us, ue, diff);

  st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

int st_query(int ss, int se, int qs, int qe, int si)
{
  st_propagate(ss, se, si);

  if (ss > se || ss > qe || se < qs)
    return 0;

  if (ss >= qs && se <= qe)
    return st[si];

  int mid = (ss + se) / 2;
  return st_query(ss, mid, qs, qe, 2 * si + 1) +
         st_query(mid + 1, se, qs, qe, 2 * si + 2);
}

void st_build(int ss, int se, int si)
{
  if (ss > se)
    return;

  if (ss == se)
  {
    st[si] = arr[ss];
    return;
  }

  int mid = (ss + se) / 2;
  st_build(ss, mid, si * 2 + 1);
  st_build(mid + 1, se, si * 2 + 2);

  st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

void st_reset()
{
  for (int i = 0; i < 4 * n; i++)
  {
    st_lazy[i] = 0;
    st[i] = 0;
  }
}

int main()
{
  return 0;
}
