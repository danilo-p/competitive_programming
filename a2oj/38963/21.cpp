#include <iostream>

#define ASCII_a 97
#define MAX_N 8

using namespace std;

int variables_order[MAX_N];

void print_identation(int size) {
    for (int i = 0; i < size; i++)
        cout << " ";
}

void print_writeln(int n) {
    print_identation(2 * n);
    cout << "writeln(";
    for (int i = 0; i < n; i++)
        if (i == 0) cout << (char) (ASCII_a + variables_order[i]);
        else cout << "," << (char) (ASCII_a + variables_order[i]);
    cout << ")" << endl;
}

void print_if_statements(int n, int current) {
    if (current >= n) {
        print_writeln(n);
        return;
    }

    int i, j, original_variables_order[n];
    for (i = 0; i < n; i++)
        original_variables_order[i] = variables_order[i];

    for (i = current; i >= 0; i--) {
        // Build the current order
        for (j = 0; j < n + 1; j++) {
            if (j < i) variables_order[j] = original_variables_order[j];
            else if (j > i) variables_order[j] = original_variables_order[j - 1];
            else variables_order[j] = current;
        }

        // Print if statement
        print_identation(2 * current);
        if (i > 0) {
            if (i < current) cout << "else ";
            cout << "if "
                 << (char) (ASCII_a + variables_order[i - 1])
                 << " < "
                 << (char) (ASCII_a + variables_order[i])
                 << " then" << endl;
        } else {
            cout << "else" << endl;
        }

        print_if_statements(n, current + 1);
    }
}

void print_variables(int n) {
    for (int i = 0; i < n; i++)
        if (i == 0) cout << (char) ASCII_a;
        else cout << "," << (char) (ASCII_a + i);
}

void build_sort_program(int n) {
    int i;

    // Header
    cout << "program sort(input,output);" << endl;

    // Variables
    cout << "var" << endl;
    print_variables(n);
    cout << " : integer;" << endl;

    // Begin
    cout << "begin" << endl;
    cout << "  readln(";
    print_variables(n);
    cout << ");" << endl;

    // If statements
    variables_order[0] = 0;
    print_if_statements(n, 1);

    // End
    cout << "end." << endl;
}

int main() {
    int m, n;

    cin >> m;
    while (m--) {
        cin >> n;
        build_sort_program(n);
        if (m > 0) cout << endl;
    }

    return 0;
}