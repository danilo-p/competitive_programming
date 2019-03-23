#include <iostream>

#define MAX_N 200
#define COLORS_NUMBER 2

using namespace std;

int n, e, graph[MAX_N][MAX_N], v_color[MAX_N];

void reset_graph() {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            v_color[i] = 0;
            graph[i][j] = 0;
        }
}

void read_edges() {
    int v1, v2;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

bool is_valid(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == v_color[i])
            return false;
    return true;
}

bool is_bicolorable(int v) {
    // If all vertices were assigned
    if (v == n) return true;

    // Try to assign the first color
    if (is_valid(v, 1)) {
        v_color[v] = 1;
        if (is_bicolorable(v + 1)) return true;
    }

    // Can't assign the first color for v
    v_color[v] = 0;

    // Try to assign the second color
    if (is_valid(v, 2)) {
        v_color[v] = 2;
        if (is_bicolorable(v + 1)) return true;
    }

    // Can't assign the second color for v
    v_color[v] = 0;

    return false;
}

int main() {
    cin >> n;
    while (n) {
        cin >> e;
        reset_graph();
        read_edges();
        if (is_bicolorable(0)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
        cin >> n;
    }

    return 0;
}