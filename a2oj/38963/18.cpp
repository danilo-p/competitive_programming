#include <iostream>
#include <string>

#define ALPHABET_SIZE 26
#define ASCII_A 97

using namespace std;

bool is_on_graph[ALPHABET_SIZE];
int union_find[ALPHABET_SIZE];
int vertex_balance[ALPHABET_SIZE];

void reset_structures() {
    for (int i = 0; i < ALPHABET_SIZE; i++){
        is_on_graph[i] = false;
        union_find[i] = i;
        vertex_balance[i] = 0;
    }
}

int uf_find(int x) {
    if (union_find[x] == x)
        return x;
    return uf_find(union_find[x]);
}

void uf_union(int x, int y) {
    int parent_x = uf_find(x);
    int parent_y = uf_find(y);
    union_find[parent_x] = parent_y;
}

bool is_solvable() {
    int i, difference_count, last_different_balance, first_parent;

    bool solvable = true;
    difference_count = 0;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (vertex_balance[i] == 0)
            continue;

        if (vertex_balance[i] != 1 && vertex_balance[i] != -1) {
            solvable = false;
            break;
        }

        difference_count++;
        if (difference_count > 2) {
            solvable = false;
            break;
        }
    }

    if (solvable) {
        first_parent = -1;
        for (i = 0; i < ALPHABET_SIZE; i++) {
            if (!is_on_graph[i]) continue;

            if (first_parent == -1) {
                first_parent = uf_find(union_find[i]);
                continue;
            }

            if (uf_find(union_find[i]) != first_parent) {
                solvable = false;
                break;
            }
        }
    }

    return solvable;
}

int main() {
    int t, n, i;
    string word;
    char first_letter_index, last_letter_index;

    cin >> t;
    while (t--) {
        cin >> n;

        reset_structures();

        for (i = 0; i < n; i++) {
            cin >> word;

            first_letter_index = word[0] - ASCII_A;
            last_letter_index = word[word.size() - 1] - ASCII_A;

            uf_union(first_letter_index, last_letter_index);

            is_on_graph[first_letter_index] = true;
            is_on_graph[last_letter_index] = true;
            
            vertex_balance[first_letter_index]++;
            vertex_balance[last_letter_index]--;
        }

        if (is_solvable()) {
            cout << "Ordering is possible.\n";
        } else {
            cout << "The door cannot be opened.\n";
        }
    }

    return 0;
}