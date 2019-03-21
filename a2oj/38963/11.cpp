#include <iostream>
#include <iomanip>
#include <vector>

#define ASCII_0 48

using namespace std;

vector< vector<char> > maze;
vector< vector<int> > visited_count;

char turn_left(char dir) {
    if (dir == 'u')
        return 'l';
    if (dir == 'l')
        return 'd';
    if (dir == 'd')
        return 'r';
    if (dir == 'r')
        return 'u';
    return 'n';
}

bool can_move(int i, int j, char dir, int lines_count, int columns_count) {
    return ((dir == 'u') && (i - 1 >= 0 && maze[i - 1][j] == '0'))
        || ((dir == 'd') && (i + 1 < lines_count && maze[i + 1][j] == '0'))
        || ((dir == 'r') && (j + 1 < columns_count && maze[i][j + 1] == '0'))
        || ((dir == 'l') && (j - 1 >= 0 && maze[i][j - 1] == '0'));
}

void calculate_and_print() {
    int i, j, not_visited = 0, visited_one = 0, visited_twice = 0, visited_thrice = 0, visited_four = 0;

    for (i = 0; i < visited_count.size(); i++) {
        for (j = 0; j < visited_count[i].size(); j++) {
            if (maze[i][j] != '0') continue;

            if (visited_count[i][j] == 0)
                not_visited++;
            else if (visited_count[i][j] == 1)
                visited_one++;
            else if (visited_count[i][j] == 2)
                visited_twice++;
            else if (visited_count[i][j] == 3)
                visited_thrice++;
            else if (visited_count[i][j] == 4)
                visited_four++;
        }
    }

    cout << setfill(' ') << setw(3) << not_visited;
    cout << setfill(' ') << setw(3) << visited_one;
    cout << setfill(' ') << setw(3) << visited_twice;
    cout << setfill(' ') << setw(3) << visited_thrice;
    cout << setfill(' ') << setw(3) << visited_four;
    cout << endl;
}

int main() {
    int i, j, lines_count, columns_count, prev_i, prev_j;
    char cell, dir;
    bool first_step;

    cin >> lines_count;
    cin >> columns_count;
    while (lines_count > 0 && columns_count > 0) {
        maze = vector< vector<char> >(lines_count, vector<char>(columns_count));
        visited_count = vector< vector<int> >(lines_count, vector<int>(columns_count, 0));
        first_step = true;

        for (i = 0; i < lines_count; i++)
            for (j = 0; j < columns_count; j++)
                cin >> maze[i][j];

        i = lines_count - 1;
        j = 0;
        dir = 'r';

        while (first_step || (!first_step && (i != lines_count - 1 || j != 0))) {
            first_step = false;

            visited_count[i][j]++;

            while (!can_move(i, j, dir, lines_count, columns_count)) dir = turn_left(dir);

            if (dir == 'u' && i - 1 >= 0 && maze[i - 1][j] == '0') {
                i = i - 1;
                if (j + 1 < columns_count && maze[i][j + 1] == '0') dir = 'r';
            } else if (dir == 'd' && i + 1 < lines_count && maze[i + 1][j] == '0') {
                i = i + 1;
                if (j - 1 >= 0 && maze[i][j - 1] == '0') dir = 'l';
            } else if (dir == 'r' && j + 1 < columns_count && maze[i][j + 1] == '0') {
                j = j + 1;
                if (i + 1 < lines_count && maze[i + 1][j] == '0') dir = 'd';
            } else if (dir == 'l' && j - 1 >= 0 && maze[i][j - 1] == '0') {
                j = j - 1;
                if (i - 1 >= 0 && maze[i - 1][j] == '0') dir = 'u';
            }
        }

        calculate_and_print();

        cin >> lines_count;
        cin >> columns_count;
    }
    return 0;
}