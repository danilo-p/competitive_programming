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
	bool square_found;
	char direction;
	set< pair<int, int> > dot_lines;

	cin >> n;
	cases = 0;
	while (cin >> n) {
		reset_board(n);

		cases++;
		cout << "Problem #" << cases << endl << endl;

		// Get the lines
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> direction;

			if (direction == 'H') {
				cin >> column;
				cin >> row;
				board[make_pair(row, column)].insert(make_pair(row, column + 1));
			}

			if (direction == 'V') {
				cin >> row;
				cin >> column;
				board[make_pair(column, row)].insert(make_pair(column, row + 1));
			}
		}

		// Count squares
		squares = 0;
		for (size = 1; size < n; size++) {
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
				}
			}

			// Print the squares count for this size
			if (squares > 0) {
				cout << squares << " square (s) of size " << size << endl;
			}
		}

		cout << endl << "**********************************" << endl;
	}

	return 0;
}