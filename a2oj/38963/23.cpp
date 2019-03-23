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
                    // Top right
                    white_king_position.second + 1 < BOARD_SIZE
                    && board[white_king_position.first - 1][white_king_position.second + 1] == 'p'
                ) || (
                    // Top left
                    white_king_position.second - 1 >= 0
                    && board[white_king_position.first - 1][white_king_position.second - 1] == 'p'
                )
            )
        );
    }

    return (
        black_king_position.first + 1 < BOARD_SIZE && (
            (
                // Bottom right
                black_king_position.second + 1 < BOARD_SIZE
                && board[black_king_position.first + 1][black_king_position.second + 1] == 'P'
            ) || (
                // Bottom left
                black_king_position.second - 1 >= 0
                && board[black_king_position.first + 1][black_king_position.second - 1] == 'P'
            )
        )
    );
}

bool check_knights(bool white) {
    char opposite_knight = 'N';
    position_t king_position = black_king_position;

    if (white) {
        opposite_knight = 'n';
        king_position = white_king_position;
    }

    return (
        // Top left/right
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
        // Bottom left/right
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
        // Right top/bottom
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
        // Left top/bottom
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
    position_t king_position = black_king_position;

    if (white) {
        opposite_king = 'k';
        king_position = white_king_position;
    }

    return (
        // Top left/right
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
        // Bottom left/right
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
        // Right top/bottom
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
        // Left top/bottom
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

    char opposite_rook = 'R';
    position_t king_position = black_king_position;

    if (white) {
        opposite_rook = 'r';
        king_position = white_king_position;
    }

    // Top
    for (i = king_position.first + 1; i < BOARD_SIZE; i++)
        if (board[i][king_position.second] == opposite_rook)
            return true;
        else if (board[i][king_position.second] != '.')
            break;

    // Bottom
    for (i = king_position.first - 1; i >= 0; i--)
        if (board[i][king_position.second] == opposite_rook)
            return true;
        else if (board[i][king_position.second] != '.')
            break;

    // Right
    for (i = king_position.second + 1; i < BOARD_SIZE; i++)
        if (board[king_position.first][i] == opposite_rook)
            return true;
        else if (board[king_position.first][i] != '.')
            break;

    // Left
    for (i = king_position.second - 1; i >= 0; i--)
        if (board[king_position.first][i] == opposite_rook)
            return true;
        else if (board[king_position.first][i] != '.')
            break;

    return false;
}

bool check_bishops(bool white) {
    int i;

    char opposite_bishop = 'B';
    position_t king_position = black_king_position;

    if (white) {
        opposite_bishop = 'b';
        king_position = white_king_position;
    }

    // Bottom right
    for (i = 1;
        king_position.first + i < BOARD_SIZE && king_position.second + i < BOARD_SIZE;
        i++)
        if (board[king_position.first + i][king_position.second + i] == opposite_bishop)
            return true;
        else if (board[king_position.first + i][king_position.second + i] != '.')
            break;

    // Top left
    for (i = 1;
        king_position.first - i >= 0 && king_position.second - i >= 0;
        i++)
        if (board[king_position.first - i][king_position.second - i] == opposite_bishop)
            return true;
        else if (board[king_position.first - i][king_position.second - i] != '.')
            break;

    // Top right
    for (i = 1;
        king_position.first - i >= 0 && king_position.second + i < BOARD_SIZE;
        i++)
        if (board[king_position.first - i][king_position.second + i] == opposite_bishop)
            return true;
        else if (board[king_position.first - i][king_position.second + i] != '.')
            break;

    // Bottom left
    for (i = 1;
        king_position.first + i < BOARD_SIZE && king_position.second - i >= 0;
        i++)
        if (board[king_position.first + i][king_position.second - i] == opposite_bishop)
            return true;
        else if (board[king_position.first + i][king_position.second - i] != '.')
            break;

    return false;
}

bool check_queens(bool white) {
    int i;

    char opposite_queen = 'Q';
    position_t king_position = black_king_position;

    if (white) {
        opposite_queen = 'q';
        king_position = white_king_position;
    }

    // Top
    for (i = king_position.first + 1; i < BOARD_SIZE; i++)
        if (board[i][king_position.second] == opposite_queen)
            return true;
        else if (board[i][king_position.second] != '.')
            break;

    // Bottom
    for (i = king_position.first - 1; i >= 0; i--)
        if (board[i][king_position.second] == opposite_queen)
            return true;
        else if (board[i][king_position.second] != '.')
            break;

    // Right
    for (i = king_position.second + 1; i < BOARD_SIZE; i++)
        if (board[king_position.first][i] == opposite_queen)
            return true;
        else if (board[king_position.first][i] != '.')
            break;

    // Left
    for (i = king_position.second - 1; i >= 0; i--)
        if (board[king_position.first][i] == opposite_queen)
            return true;
        else if (board[king_position.first][i] != '.')
            break;

    // Bottom right
    for (i = 1;
        king_position.first + i < BOARD_SIZE && king_position.second + i < BOARD_SIZE;
        i++)
        if (board[king_position.first + i][king_position.second + i] == opposite_queen)
            return true;
        else if (board[king_position.first + i][king_position.second + i] != '.')
            break;

    // Top left
    for (i = 1;
        king_position.first - i >= 0 && king_position.second - i >= 0;
        i++)
        if (board[king_position.first - i][king_position.second - i] == opposite_queen)
            return true;
        else if (board[king_position.first - i][king_position.second - i] != '.')
            break;

    // Top right
    for (i = 1;
        king_position.first - i >= 0 && king_position.second + i < BOARD_SIZE;
        i++)
        if (board[king_position.first - i][king_position.second + i] == opposite_queen)
            return true;
        else if (board[king_position.first - i][king_position.second + i] != '.')
            break;

    // Bottom left
    for (i = 1;
        king_position.first + i < BOARD_SIZE && king_position.second - i >= 0;
        i++)
        if (board[king_position.first + i][king_position.second - i] == opposite_queen)
            return true;
        else if (board[king_position.first + i][king_position.second - i] != '.')
            break;

    return false;
}

bool check_white_king() {
    return (
        check_pawns(true)
        || check_knights(true)
        || check_bishops(true)
        || check_rooks(true)
        || check_queens(true)
        || check_kings(true)
    );
}

bool check_black_king() {
    return (
        check_pawns(false)
        || check_knights(false)
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