#include <iostream>

using namespace std;

int main() {
	int a, c, b[100000], i, j, t, pt, h;
	cin >> a >> c;
	while (a && c) {
		for (i = 0; i < c; i++) {
			cin >> b[i];

			// Find max height
			if (i == 0) h = b[i];
			else h = h < b[i] ? b[i] : h;
		}

		t = 0;
		for (i = 0; i <= h; i++) {
			pt = t;
			for (j = 1; j < c; j++) {
				if (
					(b[j - 1] == i && b[j] != i)
					|| (j == c - 1 && b[j] == i && b[j - 1] != i)
				) t++;

				cout << i << "(" << t << ")" << ": " << b[j - 1] << " " << b[j] << endl;
			}
			if (t > 0 && pt == t) t++;
			cout << endl;
		}

		cout << t << endl << endl;
		cin >> a >> c;
	}
	return 0;
}