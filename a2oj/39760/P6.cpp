#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int n, m;
pair<int, int> dots[MAX_N + MAX_M];

bool ccw(pair<int, int> pi, pair<int, int> pj, pair<int, int> pk)
{
  pair<int, int> v = make_pair(pi.first - pj.first, pi.second - pj.second),
                 w = make_pair(pi.first - pk.first, pi.second - pk.second);
  int cross_product = v.first * w.second - v.second * w.first;
  return cross_product > 0;
}

bool dot_inside_triangle(int i, int j, int k, int l)
{
  pair<int, int> pi = dots[i],
                 pj = dots[j],
                 pk = dots[k],
                 pl = dots[l];
  return (
    (!ccw(pi, pj, pl) && !ccw(pj, pk, pl) && !ccw(pk, pi, pl))
    || (ccw(pi, pj, pl) && ccw(pj, pk, pl) && ccw(pk, pi, pl))
  );
}

int main()
{
  while (cin >> n >> m)
  {
    for (int i = 0; i < n + m; i++)
      cin >> dots[i].first >> dots[i].second;

    int total_energy = 0;
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
        for (int k = j; k < n; k++)
          if (i != j && i != k && j != k) {
            int triangle_energy = 0;
            for (int l = n; l < n + m; l++) {
              if (dot_inside_triangle(i, j, k, l))
                triangle_energy++;
            }
            total_energy += triangle_energy * triangle_energy;
          }

    cout << total_energy << endl;
  }
}