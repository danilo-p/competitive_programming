#include <iostream>
#include <set>
#include <cmath>
#include <climits>

#define MAX_N 10000

using namespace std;

int main() {
	int numbers[MAX_N], t, n, i, j, m, s;
	set<int> z;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> numbers[i];

		z.clear();
		for (i = 1; i <= pow(2, n) - 1; i++) {
			s = 0;
			for (j = 0; j < n; j++)
				if (i & (1 << j))
					s += numbers[j];
			z.insert(s);
		}

		m = 1;
		while (z.find(m) != z.end()) m++;

		cout << m << endl;
	}
	return 0;
}