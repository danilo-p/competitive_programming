#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long int read_binary() {
    string bin;
    int i;
    long long int dec;
    cin >> bin;
    dec = 0;
    for (i = 0; i < bin.size(); i++)
        if (bin[bin.size() - i - 1] == '1')
            dec += pow(2, i);
    return dec;
}

long long int gcd(long long int a, long long int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n, i, j;
    long long int n1, n2, base;
    bool love;
    cin >> n;

    for (i = 0; i < n; i++) {
        n1 = read_binary();
        n2 = read_binary();

        cout << "Pair #" << (i + 1) << ": ";
        if (gcd(n1, n2) > 1) cout << "All you need is love!" << endl;
        else cout << "Love is not all you need!" << endl;
    }

    return 0;
}