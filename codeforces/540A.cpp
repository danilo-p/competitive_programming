#include <bits/stdc++.h>

#define ASCII_0 0

using namespace std;

int main() {
    int n, i, actions = 0, steps;
    string current, passwd;

    cin >> n;
    cin >> current;
    cin >> passwd;

    for (i = 0; i < n; i++) {
        steps = abs(current[i] - passwd[i]);
        if (steps < 5) {
            actions += steps;
        } else {
            if (current[i] < passwd[i]) {
                actions += (10 - (passwd[i] - ASCII_0)) + (current[i] - ASCII_0);
            } else {
                actions += (10 - (current[i] - ASCII_0)) + (passwd[i] - ASCII_0);
            }
        }
    }

    cout << actions << endl;

    return 0;
}
