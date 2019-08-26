#include <bits/stdc++.h>

using namespace std;

int cross_product(pair<int, int> v, pair<int, int> w)
{
  return v.first * w.second - v.second * w.first;
}

int dot_product(pair<int, int> v, pair<int, int> w)
{
  return v.first * w.first + v.second * w.second;
}

double dots_dist(pair<int, int> p1, pair<int, int> p2)
{
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

pair<int, int> build_vector(pair<int, int> p1, pair<int, int> p2)
{
  return make_pair(p2.first - p1.first, p2.second - p1.second);
}

bool ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
  pair<int, int> v = build_vector(p2, p1),
                 w = build_vector(p3, p1);
  return cross_product(v, w) > 0;
}

int compare_angles(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2)
{
  pair<int, int> base = make_pair(p0.first, p0.second - 1),
                 v = build_vector(base, p0),
                 w = build_vector(p1, p0),
                 z = build_vector(p2, p0);

  int v_size = dots_dist(p0, base),
      w_size = dots_dist(p0, p1),
      z_size = dots_dist(p0, p2);

  double vw_cos = dot_product(v, w) / ((double)v_size * w_size);
  double vw_sin = cross_product(v, w) / ((double)v_size * w_size);
  double vw_angle_rad = atan2(vw_sin, vw_cos);
  double vw_angle = abs(vw_angle_rad * 180 / M_PI);

  double vz_cos = dot_product(v, z) / ((double)v_size * z_size);
  double vz_sin = cross_product(v, z) / ((double)v_size * z_size);
  double vz_angle_rad = atan2(vz_sin, vz_cos);
  double vz_angle = abs(vz_angle_rad * 180 / M_PI);

  if (vw_angle > vz_angle)
    return 1;
  if (vw_angle < vz_angle)
    return -1;

  if (w_size > z_size)
    return 1;
  if (w_size < z_size)
    return -1;

  return 0;
}

void sort_by_angle(pair<int, int> p0, vector<pair<int, int> > &dots, int s, int e)
{
  int i = s, j = e - 1;
  pair<int, int> pivot = dots[(s + e) / 2], aux;
  while (i <= j)
  {
    while (compare_angles(p0, dots[i], pivot) == -1 && i < e)
      i++;
    while (compare_angles(p0, dots[j], pivot) == 1 && j > s)
      j--;
    if (i <= j)
    {
      aux = dots[i];
      dots[i] = dots[j];
      dots[j] = aux;
      i++;
      j--;
    }
  }
  if (j > s)
    sort_by_angle(p0, dots, s, j + 1);
  if (i < e)
    sort_by_angle(p0, dots, i, e);
}

vector<pair<int, int> > convex_hull(vector<pair<int, int> > &dots)
{
  int n = dots.size();
  int left_most_dot_index = 0;
  for (int i = 0; i < n; i++)
    if (dots[i].first < dots[left_most_dot_index].first)
      left_most_dot_index = i;

  pair<int, int> left_most_dot = dots[left_most_dot_index];

  sort_by_angle(left_most_dot, dots, 0, dots.size());

  vector<pair<int, int> > queue;

  queue.push_back(left_most_dot);
  for (int i = 1; i < n; i++)
  {
    while (queue.size() >= 2 && !ccw(queue[queue.size() - 2], queue[queue.size() - 1], dots[i]))
      queue.pop_back();
    queue.push_back(dots[i]);
  }

  return queue;
}

int main()
{
  int n, x, y;
  vector<pair<int, int> > dots;
  std::ios::sync_with_stdio(false);
  while (cin >> n && n)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> x >> y;
      dots.push_back(make_pair(x, y));
    }

    vector<pair<int, int> > ch_dots = convex_hull(dots);
    for (int i = 0; i < ch_dots.size(); i++)
    {
      cout << "x: " << ch_dots[i].first << ", y: " << ch_dots[i].second << endl;
    }
  }
  return 0;
}