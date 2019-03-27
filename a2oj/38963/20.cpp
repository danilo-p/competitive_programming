#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x, y, r, d, s;
    cin >> n;
    while (n) {
        r = ceil(sqrt(n));
        d = pow(r, 2) - (r - 1);
        s = abs(d - n);

        if (r % 2 == 0) {
            if (n > d) {
                x = r;
                y = r - s;
            } else {
                x = r - s;
                y = r;
            }
        } else {
            if (n > d) {
                x = r - s;
                y = r;
            } else {
                x = r;
                y = r - s;
            }
        }

        cout << x << " " << y << endl;

        cin >> n;
    }
    return 0;
}