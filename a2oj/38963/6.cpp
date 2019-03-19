#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

map< pair<int, int>, set<pair<int, int> > > board;

void reset_board(int n) {
	board.clear();

	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			board[make_pair(i, j)]; // Just read to build the set
}

int main() {
	int n, m, row, column, squares, size, k, cases, i, j;
	bool square_found, some_square_found;
	char direction;
	set< pair<int, int> > dot_lines;

	cases = 0;
	while (scanf("%d", &n) != EOF) {
		reset_board(n);

		// Get the lines
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> direction;

			if (direction == 'H') {
				cin >> row;
				cin >> column;
				board[make_pair(row, column)].insert(make_pair(row, column + 1));
			}

			if (direction == 'V') {
				cin >> column;
				cin >> row;
				board[make_pair(row, column)].insert(make_pair(row + 1, column));
			}
		}

		if (cases > 0) {
			cout << endl << "**********************************" << endl << endl;
		}

		cases++;
		cout << "Problem #" << cases << endl << endl;

		// Count squares
		some_square_found = false;
		for (size = 1; size < n; size++) {
			squares = 0;

			// Try to find squares
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					square_found = true;

					// Check up line
					for (k = 0; k < size; k++) {
						dot_lines = board[make_pair(i, j + k)];
						if (dot_lines.find(make_pair(i, j + k + 1)) == dot_lines.end()) {
							square_found = false;
							break;
						}
					}

					if (!square_found) continue;

					// Check right line
					for (k = 0; k < size; k++) {
						dot_lines = board[make_pair(i + k, j + size)];
						if (dot_lines.find(make_pair(i + k + 1, j + size)) == dot_lines.end()) {
							square_found = false;
							break;
						}
					}

					if (!square_found) continue;

					// Check bottom line
					for (k = 0; k < size; k++) {
						dot_lines = board[make_pair(i + size, j + k)];
						if (dot_lines.find(make_pair(i + size, j + k + 1)) == dot_lines.end()) {
							square_found = false;
							break;
						}
					}

					if (!square_found) continue;

					// Check left line
					for (k = 0; k < size; k++) {
						dot_lines = board[make_pair(i + k, j)];
						if (dot_lines.find(make_pair(i + k + 1, j)) == dot_lines.end()) {
							square_found = false;
							break;
						}
					}

					if (!square_found) continue;

					squares++;
					some_square_found = true;
				}
			}

			// Print the squares count for this size
			if (squares > 0) {
				cout << squares << " square (s) of size " << size << endl;
			}
		}

		if (!some_square_found) {
			cout << "No completed squares can be found." << endl;
		}
	}

	return 0;
}