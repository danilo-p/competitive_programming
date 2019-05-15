#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

int n, N[MAX_N], LIS[MAX_N], LIS_I[MAX_N];

void print_solution(int max_found_index) {
    if (LIS_I[max_found_index] != max_found_index) {
        print_solution(LIS_I[max_found_index]);
        cout << " ";
    }
    cout << (max_found_index + 1);
}

int main() {
    int i, j, max_found, max_found_index;

    cin >> n;
    for (i = 0; i < n; i++) cin >> N[i];

    memset(LIS, 0, sizeof LIS);
    memset(LIS_I, 0, sizeof LIS_I);

    LIS[0] = 1;
    LIS_I[0] = 0;
    for (i = 1; i < n; i++) {
        max_found = 1;
        max_found_index = i;

        for (j = i - 1; j >= 0; j--) {
            if (N[j] == N[i] - 1 && max_found <= LIS[j] + 1) {
                max_found = LIS[j] + 1;
                max_found_index = j;
            }
        }

        LIS[i] = max_found;
        LIS_I[i] = max_found_index;
    }

    max_found = LIS[0];
    max_found_index = 0;
    for (i = 1; i < n; i++) {
        if (max_found <= LIS[i]) {
            max_found = LIS[i];
            max_found_index = i;
        }
    }

    cout << max_found << endl;

    print_solution(max_found_index);
    cout << endl;

    return 0;
}