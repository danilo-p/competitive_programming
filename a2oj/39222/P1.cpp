#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> translations;
    int n, m, i;
    string name, language, greeting;

    scanf("%d\n", &n);
    while (n--) {
        getline(cin, language);
        getline(cin, greeting);
        translations[language] = greeting;
    }

    scanf("%d\n", &m);
    while (m--) {
        getline(cin, name);
        getline(cin, language);
        cout << name << endl;
        cout << translations[language] << endl << endl;
    }

    return 0;
}