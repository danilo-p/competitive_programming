#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string j;
    set<string> js;

    while(getline(cin, j)) {
        js.insert(j);
    }

    cout << js.size() << endl;

    return 0;
}