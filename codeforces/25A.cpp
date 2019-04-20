#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, i, even_count, odd_count, last_even_index, last_odd_index;

    cin >> n;

    even_count = 0;
    odd_count = 0;
    for (i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            last_even_index = i;
            even_count++;
        } else {
            last_odd_index = i;
            odd_count++;
        }
    }

    if (even_count < odd_count) {
        cout << (last_even_index + 1) << endl;
    } else {
        cout << (last_odd_index + 1) << endl;
    }

    return 0;
}