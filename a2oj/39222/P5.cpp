#include <iostream>
#include <cmath>

#define MAX_SLOTS 250
#define MAX_BALLS 125

using namespace std;

int taken_slots[MAX_SLOTS], slots[MAX_SLOTS], balls[MAX_BALLS], slots_count, balls_count;

int max_dealer_profit(int current_ball, int current_max_profit) {
    if (current_ball == balls_count)
        return current_max_profit;

    int partial_profit, max_profit_found, i;
    bool first_ball = true;

    for (i = 0; i < slots_count; i++) {
        if (taken_slots[i] == -1 && taken_slots[(i + 1) % slots_count] == -1) {
            taken_slots[i] = current_ball;
            taken_slots[(i + 1) % slots_count] = current_ball;

            partial_profit = max_dealer_profit(
                current_ball + 1,
                current_max_profit + (slots[i] + slots[(i + 1) % slots_count]) * balls[current_ball]
            );

            if (first_ball) {
                max_profit_found = partial_profit;
                first_ball = false;
            } else {
                max_profit_found = max(max_profit_found, partial_profit);
            }

            taken_slots[i] = -1;
            taken_slots[(i + 1) % slots_count] = -1;
        }
    }

    return max_profit_found;
}

int main() {
    int i, j;
    cin >> slots_count >> balls_count;
    while (slots_count && balls_count) {
        for (i = 0; i < slots_count; i++) {
            cin >> slots[i];
            taken_slots[i] = -1;
        }

        for (i = 0; i < balls_count; i++) {
            cin >> balls[i];
            balls[i] = -balls[i];
        }

        cout << max_dealer_profit(0, 0) << endl;

        cin >> slots_count >> balls_count;
    }

    return 0;
}