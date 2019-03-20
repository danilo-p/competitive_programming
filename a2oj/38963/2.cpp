#include <iostream>
#include <string>

using namespace std;

string find_slump(string word) {
    if (word.size() < 3)
        return "";

    if (word[0] != 'D' && word[0] != 'E')
        return "";

    if (word[1] != 'F')
        return "";

    int last_f_index = 1;
    while (word[last_f_index + 1] == 'F') last_f_index++;

    if (word[last_f_index + 1] == 'G')
        return word.substr(0, last_f_index + 2);

    string possible_slump = find_slump(word.substr(last_f_index + 1));

    if (possible_slump.empty())
        return "";

    if (word[possible_slump.size() + last_f_index] == 'G')
        return word.substr(0, possible_slump.size() + last_f_index + 1);

    return "";
}

string find_slimp(string word) {
    if (word.size() < 2)
        return "";

    if (word[0] != 'A')
        return "";

    if (word[1] == 'H')
        return word.substr(0, 2);

    if (word[1] == 'B') {
        string possible_slimp = find_slimp(word.substr(2));

        if (possible_slimp.empty())
            return "";

        if (word[possible_slimp.size() + 2] == 'C')
            return word.substr(0, possible_slimp.size() + 3);

        return "";
    }

    string possible_slump = find_slump(word.substr(1));

    if (possible_slump.empty())
        return "";

    if (word[possible_slump.size() + 1] == 'C')
        return word.substr(0, possible_slump.size() + 2);

    return "";
}

bool is_slurpy(string word) {
    string possible_slimp = find_slimp(word);

    if (possible_slimp.empty())
        return false;

    string possible_slump = word.substr(possible_slimp.size());

    string slump_found = find_slump(possible_slump);

    return slump_found == possible_slump;
}

int main() {
    int n;
    string word;

    cin >> n;

    cout <<    "SLURPYS OUTPUT" << endl;

    while (n--) {
        cin >> word;

        if (is_slurpy(word))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}