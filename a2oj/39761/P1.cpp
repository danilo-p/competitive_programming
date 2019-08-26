#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll fact(ll n) {
    ll r = 1;
    for (ll i = 1; i <= n; i++) r *= i;
    return r;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << fact(min(a, b)) << endl;
    return 0;
}