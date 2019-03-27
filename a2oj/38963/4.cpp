#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<string> names;
    map<string, int> balances;
    string name;
    int people_count, budget, gift_count, gift_value, i, j, is_first;

    is_first = 1;
    while (cin >> people_count) {
        balances.clear();
        names.clear();

        // Initialize balances
        for (i = 0; i < people_count; i++) {
            cin >> name;
            balances[name] = 0;
            names.push_back(name);
        }

        for (i = 0; i < people_count; i++) {
            // Update balance for who is giving
            cin >> name >> budget >> gift_count;
            gift_value = 0;
            if (gift_count > 0) {
                gift_value = floor(budget / gift_count);
            }
            balances[name] = balances[name] - (gift_count * gift_value);

            // Update balances for the others
            for (j = 0; j < gift_count; j++) {
                cin >> name;
                balances[name] = balances[name] + gift_value;
            }
        }

        if (is_first) {
            is_first = 0;
        } else {
            cout << endl;
        }

        for (i = 0; i < names.size(); i++) {
            name = names.at(i);
            cout << name << " " << balances[name] << endl;
        }
    }

    return 0;
}