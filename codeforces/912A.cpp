#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b, x, y, z, r;
    cin >> a >> b >> x >> y >> z;
    a -= x * 2;
    a -= y;
    b -= y;
    b -= z * 3;
    r = 0;
    if (a < 0) r += abs(a);
    if (b < 0) r += abs(b);
    cout << r << endl;
    return 0;
}