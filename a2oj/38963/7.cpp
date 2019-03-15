#include <iostream>

#define BOARD_SIZE 8

using namespace std;

char board[BOARD_SIZE][BOARD_SIZE], current_player;

void fill_board() {
    int i,  j;
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            cin >> board[i][j];
}

char other_player() {
    if (current_player == 'B')
        return 'W';
    return 'B';
}

bool is_move_valid(int r, int c) {
    int i;

    cout << "Testing for " << r << " " << c <<  endl;

    // Top left
    cout << "// Top left" << endl;
    i = 1;
    while ((r - i >= 0 && c - i >= 0) && (board[r - i][c - i] == other_player())) i++;
    if ((r - i >= 0 && c - i >= 0) && board[r - i][c - i] == current_player) return true;

    // Top
    cout << "// Top" << endl;
    i = 1;
    while ((r - i >= 0 && c >= 0) && (board[r - i][c] == other_player())) i++;
    if ((r - i >= 0 && c >= 0) && board[r - i][c] == current_player) return true;

    // Top right
    cout << "// Top right" << endl;
    i = 1;
    while ((r - i >= 0 && c + i >= 0) && (board[r - i][c + i] == other_player())) i++;
    if ((r - i >= 0 && c + i >= 0) && board[r - i][c + i] == current_player) return true;

    // Right
    cout << "// Right" << endl;
    i = 1;
    while ((r >= 0 && c + i >= 0) && (board[r][c + i] == other_player())) i++;
    if ((r >= 0 && c + i >= 0) && board[r][c + i] == current_player) return true;

    // Bottom right
    cout << "// Bottom right" << endl;
    i = 1;
    while ((r + i >= 0 && c + i >= 0) && (board[r + i][c + i] == other_player())) i++;
    if ((r + i >= 0 && c + i >= 0) && board[r + i][c + i] == current_player) return true;

    // Bottom
    cout << "// Bottom" << endl;
    i = 1;
    while ((r + i >= 0 && c >= 0) && (board[r + i][c] == other_player())) i++;
    if ((r + i >= 0 && c >= 0) && board[r + i][c] == current_player) return true;

    // Bottom left
    cout << "// Bottom left" << endl;
    i = 1;
    while ((r + i >= 0 && c - i >= 0) && (board[r + i][c - i] == other_player())) i++;
    if ((r + i >= 0 && c - i >= 0) && board[r + i][c - i] == current_player) return true;

    // Left
    cout << "// Left" << endl;
    i = 1;
    while ((r >= 0 && c - i >= 0) && (board[r][c - i] == other_player())) i++;
    if ((r >= 0 && c - i >= 0) && board[r][c - i] == current_player) return true;

    return false;
}

void list_moves() {
    int i,  j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (is_move_valid(i, j)) {
                cout << "(" << (i + 1) << "," << (j + 1) << ") ";
            }
        }
    }
    cout << endl;
}

void process_command(char command) {
    switch (command) {
        case 'L':
            list_moves();
            break;
    }
}

int main() {
    int g, i, j;
    char command;

    cin >> g;
    while (g--) {
        fill_board();
        cin >> current_player;
        cin >> command;
        while (command != 'Q') {
            process_command(command);
            cin >> command;
        }
    }

    return 0;
}