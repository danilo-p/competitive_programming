#include <bits/stdc++.h>

#define MAX_COLUMNS 50000

using namespace std;

int main() {
    int columns_count, i, max_height;
    int columns[MAX_COLUMNS];
    int tallest_increasing_slope[MAX_COLUMNS];
    int tallest_decreasing_slope[MAX_COLUMNS];

    cin >> columns_count;
    for (i = 0; i < columns_count; i++)
        cin >> columns[i];

    tallest_increasing_slope[0] = 1;
    for (i = 1; i < columns_count; i++)
        if (columns[i] > tallest_increasing_slope[i - 1])
            tallest_increasing_slope[i] = tallest_increasing_slope[i - 1] + 1;
        else
            tallest_increasing_slope[i] = columns[i];

    tallest_decreasing_slope[columns_count - 1] = 1;
    for (i = columns_count - 2; i >= 0; i--)
        if (columns[i] > tallest_decreasing_slope[i + 1])
            tallest_decreasing_slope[i] = tallest_decreasing_slope[i + 1] + 1;
        else
            tallest_decreasing_slope[i] = columns[i];

    max_height = 0;
    for (i = 0; i < columns_count; i++)
        if (tallest_increasing_slope[i] <= tallest_decreasing_slope[i])
            max_height = max(max_height, tallest_increasing_slope[i]);
    for (i = 0; i < columns_count; i++)
        if (tallest_decreasing_slope[i] <= tallest_increasing_slope[i])
            max_height = max(max_height, tallest_decreasing_slope[i]);

    cout << max_height << endl;

    return 0;
}