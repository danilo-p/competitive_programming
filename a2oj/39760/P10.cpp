#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int MAX_N = 100000;

lli n;
lli st[5 * MAX_N];
lli st_lazy[5 * MAX_N];
lli arr[MAX_N];

void st_propagate(lli si, lli ss, lli se)
{
  if (st_lazy[si] != 0)
  {
    st[si] += (se - ss + 1) * st_lazy[si];

    if (ss != se)
    {
      st_lazy[si * 2 + 1] += st_lazy[si];
      st_lazy[si * 2 + 2] += st_lazy[si];
    }

    st_lazy[si] = 0;
  }
}

void st_update(lli si, lli ss, lli se, lli us,
               lli ue, lli diff)
{
  st_propagate(si, ss, se);

  if (ss > se || ss > ue || se < us)
    return;

  if (ss >= us && se <= ue)
  {
    st[si] += (se - ss + 1) * diff;

    if (ss != se)
    {
      st_lazy[si * 2 + 1] += diff;
      st_lazy[si * 2 + 2] += diff;
    }
    return;
  }

  lli mid = (ss + se) / 2;
  st_update(si * 2 + 1, ss, mid, us, ue, diff);
  st_update(si * 2 + 2, mid + 1, se, us, ue, diff);

  st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

lli st_query(lli si, lli ss, lli se, lli qs, lli qe)
{
  st_propagate(si, ss, se);

  if (ss > se || ss > qe || se < qs)
    return 0;

  if (ss >= qs && se <= qe)
    return st[si];

  lli mid = (ss + se) / 2;
  return st_query(2 * si + 1, ss, mid, qs, qe) +
         st_query(2 * si + 2, mid + 1, se, qs, qe);
}

void st_build(lli si, lli ss, lli se)
{
  if (ss > se)
    return;

  if (ss == se)
  {
    st[si] = arr[ss];
    return;
  }

  lli mid = (ss + se) / 2;
  st_build(si * 2 + 1, ss, mid);
  st_build(si * 2 + 2, mid + 1, se);

  st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

void st_reset()
{
  for (lli i = 0; i < n; i++)
    arr[i] = 0;
  for (lli i = 0; i < 5 * n; i++)
  {
    st_lazy[i] = 0;
    st[i] = 0;
  }
}

int main()
{
  lli t;
  cin >> t;
  while (t--)
  {
    lli c;
    cin >> n >> c;
    st_reset();
    st_build(0, 0, n - 1);
    while (c--)
    {
      lli k, p, q, v;
      cin >> k >> p >> q;
      if (k == 0)
      {
        cin >> v;
        st_update(0, 0, n - 1, --p, --q, v);
      }
      else
      {
        cout << st_query(0, 0, n - 1, --p, --q) << endl;
      }
    }
  }
  return 0;
}
