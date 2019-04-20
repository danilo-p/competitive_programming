#include <bits/stdc++.h>

#define LIMIT 10

using namespace std;

int main() {
    int n;
    string text;
    cin >> n;
    while (n--) {
        cin >> text;
        if (text.size() > LIMIT) {
            text = text[0] + to_string(text.size() - 2) + text[text.size() - 1];
        }
        cout << text << endl;
    }
    return 0;
}