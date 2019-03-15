#include <stdio.h>

void print_char(char c) {
    switch (c) {
        case '!':
            printf("\n");
            break;
        case 'b':
            printf(" ");
            break;
        default:
            printf("%c", c);
            break;
    }
}

int main() {
    int ascii_0 = 48, ascii_9 = 57, ascii_c, times, i;
    char c;

    times = 0;
    while (scanf("%c", &c) != EOF) {
        ascii_c = c;
        if (ascii_0 <= ascii_c && ascii_c <= ascii_9){ 
            times += ascii_c - ascii_0;
        } else {
            if (times == 0) {
                print_char(c);
            } else {
                for (i = 0; i < times; i++) print_char(c);
                times = 0;
            }
        }
    }

    return 0;
}