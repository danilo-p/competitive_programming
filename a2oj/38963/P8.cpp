#include <stdio.h>
using namespace std;

int main() {
    char current;
    bool is_quote_open = false;
    while (scanf("%c", &current) != EOF) {
        if (current == '"') {
            if (is_quote_open) {
                printf("''");
            } else {
                printf("``");
            }
            is_quote_open = !is_quote_open;
        } else {
            printf("%c", current);
        }
    }
    return 0;
}