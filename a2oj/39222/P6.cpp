#include <bits/stdc++.h>

#define MAX_LINES_COUNT 100
#define MAX_COLUMNS_COUNT 100
#define MAX_PATTERNS_COUNT 100

using namespace std;

int lines_count, columns_count, patterns_count;
int board[MAX_LINES_COUNT][MAX_COLUMNS_COUNT];
char patterns[MAX_PATTERNS_COUNT][MAX_COLUMNS_COUNT];
bool compatible_patterns[MAX_PATTERNS_COUNT][MAX_PATTERNS_COUNT];
bool never_compatible[MAX_PATTERNS_COUNT];
int memo[MAX_LINES_COUNT][MAX_PATTERNS_COUNT];

void build_compatible_patterns() {
    int i, j, k;
    bool compatible;
    for (i = 0; i < patterns_count; i++) {
        never_compatible[i] = true;
        for (j = 0; j < patterns_count; j++) {
            compatible = true;
            for (k = 0; k < columns_count; k++)
                if (
                    (patterns[i][k] == '+' || patterns[i][k] == '-')
                    && patterns[i][k] == patterns[j][k]
                ) compatible = false;
            compatible_patterns[i][j] = compatible;

            if (compatible)
                never_compatible[i] = false;
        }
    }
}

int profit_with_line_and_pattern(int line, int pattern) {
    int i;
    int profit = 0;
    for (i = 0; i < columns_count; i++) {
        if (patterns[pattern][i] == '+')
            profit += board[line][i];
        else if (patterns[pattern][i] == '-')
            profit -= board[line][i];
    }
    return profit;
}

int max_prize(int current_line, int last_pattern) {
    if (current_line == lines_count)
        return 0;

    if (memo[current_line][last_pattern])
        return memo[current_line][last_pattern];

    int i, j;
    int max_profit = INT_MIN;
    for (i = 0; i < patterns_count; i++) {
        if (compatible_patterns[last_pattern][i] && !never_compatible[i]) {
            max_profit = max(max_profit, (
                profit_with_line_and_pattern(current_line, i)
                + max_prize(current_line + 1, i)
            ));
        }
    }

    memo[current_line][last_pattern] = max_profit;
    return max_profit;
}

int main() {
    int i, j;
    int max_profit;
    cin >> lines_count >> columns_count;
    while (lines_count && columns_count) {
        for (i = 0; i < lines_count; i++)
            for (j = 0; j < columns_count; j++)
                cin >> board[i][j];

        cin >> patterns_count;
        for (i = 0; i < patterns_count; i++)
            for (j = 0; j < columns_count; j++)
                cin >> patterns[i][j];

        memset(memo, 0, sizeof memo);
        memset(compatible_patterns, false, sizeof compatible_patterns);
        memset(never_compatible, false, sizeof never_compatible);

        build_compatible_patterns();

        max_profit = INT_MIN;
        for (i = 0; i < patterns_count; i++)
            if (!never_compatible[i])
                max_profit = max(max_profit, profit_with_line_and_pattern(0, i) + max_prize(1, i));

        cout << max_profit << endl;
        cin >> lines_count >> columns_count;
    }
    return 0;
}