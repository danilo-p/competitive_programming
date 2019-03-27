#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int upperright_x, upperright_y, next_robot_x, next_robot_y, robot_x, robot_y, i, lost;
    set<string> scent;
    char command, robot_orientation;
    string coordinates, commands;

    cin >> upperright_x >> upperright_y;

    // Get the coordinates and orientation
    while (cin >> robot_x >> robot_y >> robot_orientation) {
        // Get the commands
        cin >> commands;
        lost = 0;
        for (i = 0; i < commands.length(); i++) {
            // Respond to command
            command = commands[i];
            if (command == 'F') {
                next_robot_x = robot_x;
                next_robot_y = robot_y;

                if (robot_orientation == 'N') {
                    next_robot_y++;
                } else if (robot_orientation == 'S') {
                    next_robot_y--;
                } else if (robot_orientation == 'E') {
                    next_robot_x++;
                } else if (robot_orientation == 'W') {
                    next_robot_x--;
                }

                // Check LOST
                if (
                    next_robot_x < 0
                    || next_robot_x > upperright_x
                    || next_robot_y < 0
                    || next_robot_y > upperright_y
                ) {
                    coordinates = to_string(robot_x) + "," + to_string(robot_y);
                    if (scent.find(coordinates) == scent.end()) {
                        scent.insert(coordinates);
                        lost = 1;
                        break;
                    }
                } else {
                    robot_x = next_robot_x;
                    robot_y = next_robot_y;
                }
            } else if (command == 'L') {
                if (robot_orientation == 'N') {
                    robot_orientation = 'W';
                } else if (robot_orientation == 'S') {
                    robot_orientation = 'E';
                } else if (robot_orientation == 'E') {
                    robot_orientation = 'N';
                } else if (robot_orientation == 'W') {
                    robot_orientation = 'S';
                }
            } else if (command == 'R') {
                if (robot_orientation == 'N') {
                    robot_orientation = 'E';
                } else if (robot_orientation == 'S') {
                    robot_orientation = 'W';
                } else if (robot_orientation == 'E') {
                    robot_orientation = 'S';
                } else if (robot_orientation == 'W') {
                    robot_orientation = 'N';
                }
            }
        }

        cout << robot_x << " " << robot_y << " " << robot_orientation;
        if (lost) {
            cout << " LOST\n";
        } else {
            cout << "\n";
        }
    }

    return 0;
}