#include <bits/stdc++.h>

#define MAX_LINES_COUNT 100
#define MAX_COLUMNS_COUNT 100
#define MAX_ZEROS 20
#define MAX_NEGATIVES 20

using namespace std;

int lines_count, columns_count, max_zeros, max_negatives;
int matrix[MAX_LINES_COUNT][MAX_COLUMNS_COUNT];
int memo[MAX_LINES_COUNT][MAX_COLUMNS_COUNT][MAX_ZEROS][MAX_NEGATIVES];

bool can_go_futher(
    int next_i, int next_j,
    int next_max_zeros, int next_max_negatives,
    set< pair<int, char> > tries,
    pair<int, char> next_try
) {
    return tries.find(next_try) == tries.end()
        && next_i >= 0 && next_i < lines_count && next_j >= 0 && next_j < columns_count
        && (
            matrix[next_i][next_j] > 0
            || (matrix[next_i][next_j] == 0 && next_max_zeros > 0)
            || (matrix[next_i][next_j] < 0 && next_max_negatives > 0)
        );
}

int min_path_cost(int curr_i, int curr_j, int curr_max_zeros, int curr_max_negatives, set< pair<int, char> > tries) {
    if (curr_i == lines_count - 1 && curr_j == columns_count - 1)
        return matrix[curr_i][curr_j];

    if (memo[curr_i][curr_j][curr_max_zeros][curr_max_negatives])
        return memo[curr_i][curr_j][curr_max_zeros][curr_max_negatives];

    int next_max_zeros = curr_max_zeros, next_max_negatives = curr_max_negatives;
    if (matrix[curr_i][curr_j] == 0)
        next_max_zeros--;
    else if (matrix[curr_i][curr_j] < 0)
        next_max_negatives--;

    int min_cost = INT_MAX, partial_min_cost;
    pair<int, char> next_try;

    next_try = make_pair(curr_j, 'd');
    if (can_go_futher(curr_i + 1, curr_j, next_max_zeros, next_max_negatives, tries, next_try)) {
        partial_min_cost = min_path_cost(curr_i + 1, curr_j, next_max_zeros, next_max_negatives, set< pair<int, char> >());
        if (partial_min_cost != INT_MAX)
            min_cost = min(min_cost, matrix[curr_i][curr_j] + partial_min_cost);
    }

    next_try = make_pair(curr_j, 'r');
    if (can_go_futher(curr_i, curr_j + 1, next_max_zeros, next_max_negatives, tries, next_try)) {
        tries.insert(next_try);
        partial_min_cost = min_path_cost(curr_i, curr_j + 1, next_max_zeros, next_max_negatives, set< pair<int, char> >(tries));
        if (partial_min_cost != INT_MAX)
            min_cost = min(min_cost, matrix[curr_i][curr_j] + partial_min_cost);
    }

    next_try = make_pair(curr_j, 'l');
    if (can_go_futher(curr_i, curr_j - 1, next_max_zeros, next_max_negatives, tries, next_try)) {
        tries.insert(next_try);
        partial_min_cost = min_path_cost(curr_i, curr_j - 1, next_max_zeros, next_max_negatives, set< pair<int, char> >(tries));
        if (partial_min_cost != INT_MAX)
            min_cost = min(min_cost, matrix[curr_i][curr_j] + partial_min_cost);
    }

    if (min_cost != INT_MAX)
        memo[curr_i][curr_j][curr_max_zeros][curr_max_negatives] = min_cost;

    return min_cost;
}

int main() {
    int i, j, min_cost;
    while (cin >> lines_count >> columns_count >> max_zeros >> max_negatives) {
        for (i = 0; i < lines_count; i++)
            for (j = 0; j < columns_count; j++)
                cin >> matrix[i][j];

        memset(memo, 0, sizeof memo);

        min_cost = min_path_cost(0, 0, max_zeros, max_negatives, set< pair<int, char> >());
        if (min_cost == INT_MAX)
            cout << "Impossivel" << endl;
        else
            cout << min_cost << endl;
    }
    return 0;
}