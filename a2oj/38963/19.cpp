#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int c, ferry_load, trip_time, cars_total, i, j, elapsed_time, trips_count, current_waiting_time;

    cin >> c;

    while (c--) {
        cin >> ferry_load >> trip_time >> cars_total;

        i = 1;
        elapsed_time = 0;
        trips_count = ceil((cars_total * 1.0) / ferry_load);

        if (cars_total % ferry_load > 0) {
            for (i = 1; i <= (cars_total % ferry_load); i++)
                cin >> current_waiting_time;
            elapsed_time = current_waiting_time + 2 * trip_time;
        }

        for (i = 1; i <= (cars_total - (cars_total % ferry_load)); i++) {
            cin >> current_waiting_time;
            if (elapsed_time < current_waiting_time)
                elapsed_time = current_waiting_time;

            if (i % ferry_load == 0)
                elapsed_time += 2 * trip_time;
        }

        elapsed_time -= trip_time;

        cout << elapsed_time << " " << trips_count << endl;
    }

    return 0;
}