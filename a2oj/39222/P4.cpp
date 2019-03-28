#include <iostream>
#include <utility>
#include <cmath>

#define MAX_N 50
#define MAX_K 100

using namespace std;

pair<int, int> b[MAX_N];
int memo[MAX_N][MAX_K];

void reset_memo(int n, int k) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			memo[i][j] = -1;
}

int max_damage(int n, int k, int i, int current_capacity, int current_damage) {
	if (i == n || current_capacity == k)
		return current_damage;

	if (memo[i][current_capacity] >= 0)
		return memo[i][current_capacity];

	int partial_max_damage = 0;
	if (current_capacity + b[i].second <= k)
		partial_max_damage = max_damage(n, k, i + 1, current_capacity + b[i].second, current_damage + b[i].first);

	partial_max_damage = max(partial_max_damage, max_damage(n, k, i + 1, current_capacity, current_damage));

	memo[i][current_capacity] = partial_max_damage;

	return partial_max_damage;
}

int main() {
	int c, n, x, y, k, r, i, j;

	cin >> c;
	while (c--) {
		cin >> n;

		for (i = 0; i < n; i++) {
			cin >> x >> y;
			b[i] = make_pair(x, y);
		}

		cin >> k;
		cin >> r;

		reset_memo(n, k);

		if (max_damage(n, k, 0, 0, 0) >= r) {
			cout << "Missao completada com sucesso" << endl;
		} else {
			cout << "Falha na missao" << endl;
		}
	}

	return 0;
}