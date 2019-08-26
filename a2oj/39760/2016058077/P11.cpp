#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, c = 1;
  cin >> t;
  while (t--)
  {
    pair<double, double>
        p1_1,
        p2_1,
        p1_2,
        p2_2;
    cin >> p1_1.first >> p1_1.second;
    cin >> p2_1.first >> p2_1.second;
    cin >> p1_2.first >> p1_2.second;
    cin >> p2_2.first >> p2_2.second;
    double
        m1 = (p1_1.second - p1_2.second) / (p1_1.first - p1_2.first),
        m2 = (p2_1.second - p2_2.second) / (p2_1.first - p2_2.first),
        p1_x = (p1_1.first + p1_2.first) / 2.0,
        p1_y = (p1_1.second + p1_2.second) / 2.0,
        p2_x = (p2_1.first + p2_2.first) / 2.0,
        p2_y = (p2_1.second + p2_2.second) / 2.0;
    double a1, b1 = 1, c1, a2, b2 = 1, c2;

    if (p1_1.second - p1_2.second == 0) {
      a1 = 1;
      b1 = 0;
      c1 = -p1_x;
    } else if (p1_1.first - p1_2.first == 0) {
      a1 = 0;
      c1 = -p1_y;
    } else {
      double mi = -1.0 / m1;
      a1 = -mi;
      c1 = mi * p1_x - p1_y;
    }

    if (p2_1.second - p2_2.second == 0) {
      a2 = 1;
      b2 = 0;
      c2 = -p2_x;
    } else if (p2_1.first - p2_2.first == 0) {
      a2 = 0;
      c2 = -p2_y;
    } else {
      double mi = -1.0 / m2;
      a2 = -mi;
      c2 = mi * p2_x - p2_y;
    }

    double
      x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1),
      y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);

    x = x == 0 ? 0 : x;
    y = y == 0 ? 0 : y;

    printf("Caso #%d: %.2f %.2f\n", c, x, y);
    c++;
  }
  return 0;
}