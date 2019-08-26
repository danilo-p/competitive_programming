#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

ll mdc(ll a, ll b) { // a > b
    if (b == 0) return a;
    return mdc(b, a % b);
}

ll fib(ll n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    ll res = 2, prev = 1, sec_prev = 1;
    for (ll i = 2; i < n; i++) {
        sec_prev = prev;
        prev = res;
        res = prev + sec_prev;
    }

    return res;
}

int main() {
    ll n;
    while (cin >> n) {
        if (n == 1) {
            cout << "1/1" << endl;
            continue;
        }

        ll num = fib(n + 1);
        ll den = pow(2, n);
        ll mdc_num_dem = mdc(den, num);
        num /= mdc_num_dem;
        den /= mdc_num_dem;
        cout << num << "/" << den << endl;
    }
}