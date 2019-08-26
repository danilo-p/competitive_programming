#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAX_N = 10000;

ld points_dist(pair<ld, ld> p1, pair<ld, ld> p2)
{
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main()
{
  int n;
  pair<ld, ld> points[MAX_N];
  while (cin >> n && n)
  {
    for (int i = 0; i < n; i++)
      cin >> points[i].first >> points[i].second;

    ld min_found = 10000;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        min_found = min(min_found, points_dist(points[i], points[j]));

    if (min_found == 10000)
      cout << "INFINITY" << endl;
    else
      printf("%.4Lf\n", min_found);
  }
  return 0;
}