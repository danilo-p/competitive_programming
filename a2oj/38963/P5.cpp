#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, i, halted, down_count;
    bool is_down[100];
    cin >> n;
    while (n > 0) {
        m = 0;
        do {
            m++;
            for (i = 0; i < 100; i++) is_down[i] = false;
            halted = 0;
            is_down[halted] = true;
            down_count = 1;
            do {
                // Get the closest up place that may be halted
                i = 0;
                while (i < m) {
                    halted = (halted + 1) % n;
                    if (!is_down[halted]) i++;
                }
                is_down[halted] = true;
                down_count++;
            } while (halted != 12);
        } while(down_count < n);

        cout << m << endl;
        cin >> n;
    }
    return 0;
}