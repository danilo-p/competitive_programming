#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const lli MAX_N = 2000;

pair<lli, lli> p0;
pair<lli, lli> dots[MAX_N];

lli cross_product(pair<lli, lli> v, pair<lli, lli> w)
{
  return v.first * w.second - v.second * w.first;
}

lli dot_product(pair<lli, lli> v, pair<lli, lli> w)
{
  return v.first * w.first + v.second * w.second;
}

double dots_dist(pair<lli, lli> p1, pair<lli, lli> p2)
{
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

pair<lli, lli> build_vector(pair<lli, lli> p1, pair<lli, lli> p2)
{
  return make_pair(p2.first - p1.first, p2.second - p1.second);
}

lli ccw(pair<lli, lli> p1, pair<lli, lli> p2, pair<lli, lli> p3)
{
  pair<lli, lli> v = build_vector(p2, p1),
                 w = build_vector(p3, p1);
  lli vw_cross = cross_product(v, w);

  if (vw_cross > 0)
    return 1;
  else if (vw_cross < 0)
    return -1;
  return 0;
}

int compare_dots(const void *a, const void *b)
{
  pair<lli, lli> *p1 = (pair<lli, lli> *)a,
                 *p2 = (pair<lli, lli> *)b;

  pair<lli, lli> v = build_vector(*p1, p0),
                 w = build_vector(*p2, p0);

  lli v_size = dots_dist(p0, *p1),
      w_size = dots_dist(p0, *p2);

  if (ccw(p0, *p1, *p2) == -1)
    return 1;
  if (ccw(p0, *p1, *p2) == 1)
    return -1;

  if (p0.first == p1->first && p1->first == p2->first)
  {
    if (v_size < w_size)
      return 1;
    if (v_size > w_size)
      return -1;
  }

  if (v_size > w_size)
    return 1;
  if (v_size < w_size)
    return -1;

  return 0;
}

set<pair<lli, lli> > convex_hull(lli n)
{
  lli left_most_dot_index = 0;
  for (lli i = 0; i < n; i++)
    if (dots[i].first < dots[left_most_dot_index].first || (dots[i].first == dots[left_most_dot_index].first && dots[i].second < dots[left_most_dot_index].second))
      left_most_dot_index = i;

  pair<int, int> temp = dots[0];
  dots[0] = dots[left_most_dot_index];
  dots[left_most_dot_index] = temp;
  p0 = dots[0];
  qsort(&dots[1], n - 1, sizeof(pair<lli, lli>), compare_dots);

  vector<pair<lli, lli> > queue;
  queue.push_back(p0);
  for (lli i = 1; i < n; i++)
  {
    while (queue.size() >= 2 && ccw(queue[queue.size() - 2], queue[queue.size() - 1], dots[i]) == -1)
      queue.pop_back();
    queue.push_back(dots[i]);
  }

  set<pair<lli, lli> > layer_dots;
  for (lli i = 0; i < queue.size(); i++)
    layer_dots.insert(queue[i]);

  return layer_dots;
}

signed main()
{
  lli n, x, y;
  while (scanf("%lld", &n) && n)
  {
    for (lli i = 0; i < n; i++)
      scanf("%lld %lld", &dots[i].first, &dots[i].second);

    lli layers_count = 0;
    while (n > 2)
    {
      set<pair<lli, lli> > outer_layer_dots = convex_hull(n);

      lli j = 0;
      for (lli i = 0; i < n; i++)
      {
        if (outer_layer_dots.find(dots[i]) != outer_layer_dots.end())
          continue;

        dots[j] = dots[i];
        j++;
      }

      n -= outer_layer_dots.size();

      layers_count++;
    }

    if (n > 0)
      layers_count++;

    if (layers_count % 2 == 0)
      cout << "Do not take this onion to the lab!" << endl;
    else
      cout << "Take this onion to the lab!" << endl;
  }
  return 0;
}