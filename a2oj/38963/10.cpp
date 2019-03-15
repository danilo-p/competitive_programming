#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int ascii_A = 65,
    ascii_E = 69,
    ascii_I = 73,
    ascii_O = 79,
    ascii_U = 85,
    ascii_Z = 90,
    ascii_a = 97,
    ascii_e = 101,
    ascii_i = 105,
    ascii_o = 111,
    ascii_u = 117,
    ascii_z = 122;

bool is_vowel(int ascii_c) {
    return (
        ascii_c == ascii_A
        || ascii_c == ascii_E
        || ascii_c == ascii_I
        || ascii_c == ascii_O
        || ascii_c == ascii_U
        || ascii_c == ascii_a
        || ascii_c == ascii_e
        || ascii_c == ascii_i
        || ascii_c == ascii_o
        || ascii_c == ascii_u
    );
}

int main() {
    string the_word = "";
    char c, first_char;
    int ascii_c;
    while (scanf("%c", &c) != EOF) {
        ascii_c = c;
        if (
            (ascii_A <= ascii_c && ascii_c <= ascii_Z)
            || (ascii_a <= ascii_c && ascii_c <= ascii_z)
        ) {
            the_word += c;
        } else {
            if (the_word.length() > 0) {
                first_char = the_word[0];
                if (!is_vowel(first_char)) {
                    the_word.erase(0, 1);
                    the_word += first_char;
                }
                cout << the_word << "ay" << c;
            } else {
                cout << c;
            }
            the_word = "";
        }
    }
    return 0;
}