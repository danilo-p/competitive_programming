#include <bits/stdc++.h>

using namespace std;

typedef pair<double, pair<double, double> > dot_t;

const int MAX_N = 50;

void print_dot(dot_t d)
{
  cout << "x: " << d.first << endl;
  cout << "y: " << d.second.first << endl;
  cout << "z: " << d.second.second << endl;
}

dot_t build_dot(double x, double y, double z)
{
  return make_pair(x, make_pair(y, z));
}

dot_t build_vector(dot_t p, dot_t q)
{
  return build_dot(
      p.first - q.first,
      p.second.first - q.second.first,
      p.second.second - q.second.second);
}

dot_t cross_product(dot_t v, dot_t w)
{
  return build_dot(
      v.second.first * w.second.second - w.second.first * v.second.second,
      w.first * v.second.second - v.first * w.second.second,
      v.first * w.second.first - v.second.first * w.first);
}

bool equal_to_zero(double x) {
  // return x == 0;
  return (x >= 0 && x <= 1e-15) || (x <= 0 && x >= -1e-15);
}

int main()
{
  dot_t dots[MAX_N];
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> dots[i].first >> dots[i].second.first >> dots[i].second.second;

    double ans = min(n, 3);
    for (int i = 0; i < n; i++)
    {
      double ans2 = 1;
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          if (i != j && i != k && j != k)
            if (dots[i] == dots[j] && dots[i] == dots[k] && dots[j] == dots[k])
              ans2++;
      ans = max(ans, ans2);
    }

    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
        for (int k = j; k < n; k++)
          if (i != j && i != k && j != k)
            if (dots[i] != dots[j] && dots[i] != dots[k] && dots[j] != dots[k])
            {
              dot_t vij = build_vector(dots[j], dots[i]);
              dot_t vik = build_vector(dots[k], dots[i]);
              dot_t cpvik = cross_product(vij, vik);
              double
                  a = cpvik.first,
                  b = cpvik.second.first,
                  c = cpvik.second.second,
                  d = (-a * dots[i].first -b * dots[i].second.first -c * dots[i].second.second);
              if (!(a == 0 && b == 0 && c == 0)) {
                double ans2 = 0;
                for (int l = 0; l < n; l++)
                  if (equal_to_zero(a * dots[l].first + b * dots[l].second.first + c * dots[l].second.second + d))
                    ans2++;
                ans = max(ans, ans2);
              }
            }

    if (ans == 3)
      for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
          for (int k = j; k < n; k++)
            if (i != j && i != k && j != k)
              if (dots[i] != dots[j] && dots[i] != dots[k] && dots[j] != dots[k])
              {
                dot_t vij = build_vector(dots[j], dots[i]);
                dot_t vik = build_vector(dots[k], dots[i]);
                dot_t cpvik = cross_product(vij, vik);
                double
                    a = cpvik.first,
                    b = cpvik.second.first,
                    c = cpvik.second.second,
                    d = (-a * dots[i].first -b * dots[i].second.first -c * dots[i].second.second);
                if (a == 0 && b == 0 && c == 0) {
                  ans = n;
                }
              }

    cout << ans << endl;
  }
}