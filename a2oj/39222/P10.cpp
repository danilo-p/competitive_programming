#include <iostream>
#include <cmath>

#define MAX_GIFTS 10000
#define MAX_DIFERENCE 5

using namespace std;

int gifts_weight[MAX_GIFTS];

bool can_balance_sleigh(int gifts_count, int current_gift, int a_current_weight, int b_current_weight) {
    if (current_gift == gifts_count)
        return true;

    if (
        // Can put safely the gift on the side a
        abs((a_current_weight + gifts_weight[current_gift]) - b_current_weight) <= MAX_DIFERENCE
        // Can balance sleigh with the gift on the side a
        && can_balance_sleigh(gifts_count, current_gift + 1, a_current_weight + gifts_weight[current_gift], b_current_weight)
    ) return true;

    if (
        // Can put safely the gift on the side b
        abs(a_current_weight - (b_current_weight + gifts_weight[current_gift])) <= MAX_DIFERENCE
        // Can balance sleigh with the gift on the side b
        && can_balance_sleigh(gifts_count, current_gift + 1, a_current_weight, b_current_weight + gifts_weight[current_gift])
    ) return true;

    // Can't balance with the current configuration
    return false;
}

int main() {
    int cases, gifts_count, gift_weight, i;

    cin >> cases;
    while (cases--) {
        cin >> gifts_count;

        for (i = 0; i < gifts_count; i++)
            cin >> gifts_weight[i];

        if (can_balance_sleigh(gifts_count, 0, 0, 0)) {
            cout << "Feliz Natal!" << endl;
        } else {
            cout << "Ho Ho Ho!" << endl;
        }
    }

    return 0;
}