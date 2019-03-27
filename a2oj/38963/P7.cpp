#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

#define BOARD_SIZE 8
#define ASCII_0 48

using namespace std;

char board[BOARD_SIZE][BOARD_SIZE], current_player;

void fill_board() {
    int i,  j;
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            cin >> board[i][j];
}

void print_board() {
    int i,  j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++)
            cout << board[i][j];
        cout << endl;
    }
}

char other_player() {
    if (current_player == 'B')
        return 'W';
    return 'B';
}

vector< pair<char, char> > move_directions(int r, int c) {
    int i;
    vector< pair<char, char> > directions_list;

    // Check if it is occuped
    if (board[r][c] != '-') return directions_list;

    // Up Left
    i = 1;
    while ((r - i >= 0 && c - i >= 0) && (board[r - i][c - i] == other_player())) i++;
    if (i > 1 && (r - i >= 0 && c - i >= 0) && board[r - i][c - i] == current_player)
        directions_list.push_back(make_pair('u', 'l'));

    // Up
    i = 1;
    while ((r - i >= 0) && (board[r - i][c] == other_player())) i++;
    if (i > 1 && (r - i >= 0) && board[r - i][c] == current_player)
        directions_list.push_back(make_pair('u', 'n'));

    // Up right
    i = 1;
    while ((r - i >= 0 && c + i < BOARD_SIZE) && (board[r - i][c + i] == other_player())) i++;
    if (i > 1 && (r - i >= 0 && c + i < BOARD_SIZE) && board[r - i][c + i] == current_player)
        directions_list.push_back(make_pair('u', 'r'));

    // Left
    i = 1;
    while ((c - i >= 0) && (board[r][c - i] == other_player())) i++;
    if (i > 1 && (c - i >= 0) && board[r][c - i] == current_player)
        directions_list.push_back(make_pair('n', 'l'));

    // Right
    i = 1;
    while ((c + i < BOARD_SIZE) && (board[r][c + i] == other_player())) i++;
    if (i > 1 && (c + i < BOARD_SIZE) && board[r][c + i] == current_player)
        directions_list.push_back(make_pair('n', 'r'));

    // Bottom Left
    i = 1;
    while ((r + i < BOARD_SIZE && c - i >= 0) && (board[r + i][c - i] == other_player())) i++;
    if (i > 1 && (r + i < BOARD_SIZE && c - i >= 0) && board[r + i][c - i] == current_player)
        directions_list.push_back(make_pair('d', 'l'));

    // Bottom
    i = 1;
    while ((r + i < BOARD_SIZE) && (board[r + i][c] == other_player())) i++;
    if (i > 1 && (r + i < BOARD_SIZE) && board[r + i][c] == current_player)
        directions_list.push_back(make_pair('d', 'n'));

    // Bottom right
    i = 1;
    while ((r + i < BOARD_SIZE && c + i < BOARD_SIZE) && (board[r + i][c + i] == other_player())) i++;
    if (i > 1 && (r + i < BOARD_SIZE && c + i < BOARD_SIZE) && board[r + i][c + i] == current_player)
        directions_list.push_back(make_pair('d', 'r'));

    return directions_list;
}

bool is_move_valid(int r, int c) {
    vector< pair<char, char> > directions_list = move_directions(r, c);
    return directions_list.size() > 0;
}

int list_moves(bool print_moves) {
    int i,  j, moves_count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (is_move_valid(i, j)) {
                if (print_moves) {
                    if (moves_count > 0) cout << " ";
                    cout << "(" << (i + 1) << "," << (j + 1) << ")";
                }
                moves_count++;
            }
        }
    }

    if (print_moves) {
        if (moves_count == 0)
            cout << "No legal move.";
        cout << endl;
    }

    return moves_count;
}

void make_move(int row, int column) {
    if (list_moves(false) == 0) {
        current_player = current_player == 'B' ? 'W' : 'B';
    }

    vector< pair<char, char> > directions_list = move_directions(row, column);
    pair<char, char> directions;
    char h, v;
    int i, j, r, c, b_count, w_count;

    for (i = 0; i < directions_list.size(); i++) {
        directions = directions_list[i];
        h = directions.first;
        v = directions.second;

        r = row;
        c = column;

        board[r][c] = '-';
        while (
            (r >= 0 && r < BOARD_SIZE)
            && (c >= 0 && c < BOARD_SIZE)
            && board[r][c] != current_player
        ) {
            board[r][c] = current_player;

            if (h == 'u')
                r--;
            else if (h == 'd')
                r++;

            if (v == 'r')
                c++;
            else if (v == 'l')
                c--;
        }
    }

    current_player = other_player();

    b_count = 0;
    w_count = 0;
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            if (board[i][j] == 'B') b_count++;
            else if (board[i][j] == 'W') w_count++;

    cout << "Black - ";
    cout << setfill(' ') << setw(2) << b_count;
    cout << " White - ";
    cout << setfill(' ') << setw(2) << w_count;
    cout << endl;
}

void process_command(string command) {
    switch (command[0]) {
        case 'L':
            list_moves(true);
            break;
        case 'M':
            make_move(command[1] - ASCII_0 - 1, command[2] - ASCII_0 - 1);
            break;
    }
}

int main() {
    int g, i, j;
    string command;

    cin >> g;
    while (g--) {
        fill_board();
        cin >> current_player;
        cin >> command;
        while (command[0] != 'Q') {
            process_command(command);
            cin >> command;
        }
        print_board();
        if (g > 0) cout << endl;
    }

    return 0;
}