#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

int n;
int arr[MAX_N];
int st[2 * MAX_N];

int pos_neg_or_zero(int a, int b)
{
  int res = a * b;
  if (res > 0)
    return 1;
  if (res < 0)
    return -1;
  return 0;
}

char present_query(int a)
{
  if (a > 0)
    return '+';
  if (a < 0)
    return '-';
  return '0';
}

void st_build()
{
  for (int i = 0; i < n; i++)
    st[n + i] = arr[i];

  for (int i = n - 1; i > 0; --i)
    st[i] = pos_neg_or_zero(st[i << 1], st[i << 1 | 1]);
}

void st_update(int p, int value)
{
  st[p + n] = value;
  p = p + n;

  for (int i = p; i > 1; i >>= 1)
    st[i >> 1] = pos_neg_or_zero(st[i], st[i ^ 1]);
}

int st_query(int l, int r)
{
  int res = 1;

  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
      res = pos_neg_or_zero(res, st[l++]);

    if (r & 1)
      res = pos_neg_or_zero(res, st[--r]);
  }

  return res;
}

int main()
{
  int k;
  while (cin >> n >> k)
  {
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    st_build();
    char c;
    int i, j, v;
    while (k--)
    {
      cin >> c;
      if (c == 'C')
      {
        cin >> i >> v;
        st_update(--i, v);
      }
      else
      {
        cin >> i >> j;
        cout << present_query(st_query(--i, j));
      }
    }
    cout << endl;
  }
  return 0;
}
