#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int square_root(int n) {
	double n_sqrt = sqrt(n);
	int n_sqrt_i = n_sqrt;
	if (n_sqrt_i == n_sqrt)
		return n_sqrt_i;
	return 0;
}

int main() {
	int n, n_sqrt, i, j, i_pwr;

	while (scanf("%d", &n) != EOF) {
		n_sqrt = 0;

		for (i = 1; i < ceil((n + 1) / 2.0); i++) {
			i_pwr = i * i;
			n_sqrt = square_root(n - i_pwr);
			if (n_sqrt) break;
		}

		if (n_sqrt) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}