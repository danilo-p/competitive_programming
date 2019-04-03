#include <iostream>
#include <cmath>

using namespace std;

long long int factorial(int n) {
	long long int fac = n;
	while (n-- && n > 0) {
		fac = fac * n;
	}
	return fac;
}

int main() {
	long long int n, i, j, sum, fac_j, count;
	cin >> n;

	for (i = 10; i >= 1; i--) {
		sum = 0;
		count = 0;

		for (j = i; j >= 1; j--) {
			fac_j = factorial(j);

			while (fac_j && fac_j + sum <= n) {
				sum += fac_j;
				count++;
			}

			if (sum == n) {
				cout << count << endl;
				return 0;
			}
		}
	}

	return 0;
}
