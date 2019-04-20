#include <bits/stdc++.h>

#define ASCII_UPPER_OFFSET 32
#define ASCII_a 97

using namespace std;

int main() {
    string text;
    cin >> text;
    if (text[0] >= ASCII_a) {
        text[0] = text[0] - ASCII_UPPER_OFFSET;
    }
    cout << text << endl;
    return 0;
}