#include <iostream>
#include <utility>

#define BOARD_SIZE 8

using namespace std;

typedef pair<int, int> position_t;

char board[BOARD_SIZE][BOARD_SIZE];
position_t white_king_position, black_king_position;

bool read_board() {
	int i, j;
	bool end_board = true;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			cin >> board[i][j];
			if (board[i][j] != '.') end_board = false;
			if (board[i][j] == 'K') white_king_position = make_pair(i, j);
			if (board[i][j] == 'k') black_king_position = make_pair(i, j);
		}
	}

	return end_board;
}

bool check_pawns(bool white) {
	int i, j;

	if (white) {
		return (
			white_king_position.first - 1 >= 0 && (
				(
					white_king_position.second + 1 < BOARD_SIZE
					&& board[white_king_position.first - 1][white_king_position.second + 1] == 'p'
				) || (
					white_king_position.second - 1 >= 0
					&& board[white_king_position.first - 1][white_king_position.second - 1] == 'p'
				)
			)
		);
	}

	return (
		white_king_position.first + 1 >= 0 && (
			(
				white_king_position.second + 1 < BOARD_SIZE
				&& board[white_king_position.first + 1][white_king_position.second + 1] == 'P'
			) || (
				white_king_position.second - 1 >= 0
				&& board[white_king_position.first + 1][white_king_position.second - 1] == 'P'
			)
		)
	);
}

bool check_knights(bool white) {
	char opposite_knight = 'N';
	char king_position = black_king_position;

	if (white) {
		opposite_knight = 'n';
		king_position = white_king_position;
	}

	return (
		king_position.first - 2 >= 0 && (
			(
				king_position.second + 1 < BOARD_SIZE
				&& board[king_position.first - 2][king_position.second + 1] == opposite_knight
			) || (
				king_position.second - 1 >= 0
				&& board[king_position.first - 2][king_position.second - 1] == opposite_knight
			)
		)
	) || (
		king_position.first + 2 < BOARD_SIZE && (
			(
				king_position.second + 1 < BOARD_SIZE
				&& board[king_position.first + 2][king_position.second + 1] == opposite_knight
			) || (
				king_position.second - 1 >= 0
				&& board[king_position.first + 2][king_position.second - 1] == opposite_knight
			)
		)
	) || (
		king_position.second + 2 < BOARD_SIZE && (
			(
				king_position.first + 1 < BOARD_SIZE
				&& board[king_position.first + 1][king_position.second + 2] == opposite_knight
			) || (
				king_position.first - 1 >= 0
				&& board[king_position.first - 1][king_position.second + 2] == opposite_knight
			)
		)
	) || (
		king_position.second - 2 >= 0 && (
			(
				king_position.first + 1 < BOARD_SIZE
				&& board[king_position.first + 1][king_position.second - 2] == opposite_knight
			) || (
				king_position.first - 1 >= 0
				&& board[king_position.first - 1][king_position.second - 2] == opposite_knight
			)
		)
	);
}

bool check_kings(bool white) {
	char opposite_king = 'K';
	char king_position = black_king_position;

	if (white) {
		opposite_king = 'k';
		king_position = white_king_position;
	}

	return (
		king_position.first - 1 >= 0 && (
			(
				king_position.second + 1 < BOARD_SIZE
				&& board[king_position.first - 1][king_position.second + 1] == opposite_king
			) || (
				king_position.second - 1 >= 0
				&& board[king_position.first - 1][king_position.second - 1] == opposite_king
			)
		)
	) || (
		king_position.first + 1 < BOARD_SIZE && (
			(
				king_position.second + 1 < BOARD_SIZE
				&& board[king_position.first + 1][king_position.second + 1] == opposite_king
			) || (
				king_position.second - 1 >= 0
				&& board[king_position.first + 1][king_position.second - 1] == opposite_king
			)
		)
	) || (
		king_position.second + 1 < BOARD_SIZE && (
			(
				king_position.first + 1 < BOARD_SIZE
				&& board[king_position.first + 1][king_position.second + 1] == opposite_king
			) || (
				king_position.first - 1 >= 0
				&& board[king_position.first - 1][king_position.second + 1] == opposite_king
			)
		)
	) || (
		king_position.second - 1 >= 0 && (
			(
				king_position.first + 1 < BOARD_SIZE
				&& board[king_position.first + 1][king_position.second - 1] == opposite_king
			) || (
				king_position.first - 1 >= 0
				&& board[king_position.first - 1][king_position.second - 1] == opposite_king
			)
		)
	);
}

bool check_rooks(bool white) {
	int i;

	char opposite_rook = 'r';
	char king_position = white_king_position;

	if (white) {
		opposite_rook = 'R';
		king_position = black_king_position;
	}

	for (i = king_position.first; i < BOARD_SIZE; i++)
		if (board[i][king_position.second] == opposite_rook)
			return true;

	for (i = king_position.first; i >= 0; --)
		if (board[i][king_position.second] == opposite_rook)
			return true;

	for (i = king_position.second; i < BOARD_SIZE; i++)
		if (board[king_position.first][i] == opposite_rook)
			return true;

	for (i = king_position.second; i >= 0; --)
		if (board[king_position.first][i] == opposite_rook)
			return true;

	return false;
}

bool check_bishops(bool white) {
	int i;

	char opposite_bishop = 'b';
	char king_position = white_king_position;

	if (white) {
		opposite_bishop = 'B';
		king_position = black_king_position;
	}

	for (i = king_position.first;
		king_position.first + i < BOARD_SIZE && king_position.second + i < BOARD_SIZE;
		i++)
		if (board[king_position.first + i][king_position.second + i] == opposite_bishop)
			return true;

	for (i = king_position.first;
		king_position.first - i >= BOARD_SIZE && king_position.second - i >= BOARD_SIZE;
		i++)
		if (board[king_position.first - i][king_position.second - i] == opposite_bishop)
			return true;

	for (i = king_position.first;
		king_position.first + i < BOARD_SIZE && king_position.second + i < BOARD_SIZE;
		i++)
		if (board[king_position.first + i][king_position.second + i] == opposite_bishop)
			return true;

	for (i = king_position.first;
		king_position.first - i >= BOARD_SIZE && king_position.second - i >= BOARD_SIZE;
		i++)
		if (board[king_position.first - i][king_position.second - i] == opposite_bishop)
			return true;

	return false;
}

bool check_queens(bool white) {

}

bool check_white_king() {
	return (
		check_knights(true)
		|| check_bishops(true)
		|| check_rooks(true)
		|| check_queens(true)
		|| check_kings(true)
	);
}

bool check_black_king() {
	return (
		check_knights(false)
		|| check_bishops(false)
		|| check_rooks(false)
		|| check_queens(false)
		|| check_kings(false)
	);
}

int main() {
	int i, j, games = 0;
	bool last_board;

	while(!read_board()) {
		games++;

		cout << "Game #" << games << ": ";
		if (check_white_king()) {
			cout << "white king is in check." << endl;
		} else if (check_black_king()) {
			cout << "black king is in check." << endl;
		} else {
			cout << "no king is in check." << endl;
		}
	}

	return 0;
}