#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    char c;
    stack<char> s;
    int n, diamonds_count;

    scanf("%d\n", &n);
    while (n--) {
        diamonds_count = 0;
        s = stack<char>();

        while (scanf("%c", &c) != EOF && c != '\n') {

            if (c == '<') {
                s.push(c);
            }

            if (c == '>' && s.size()) {
                s.pop();
                diamonds_count++;
            }
        }

        printf("%d\n", diamonds_count);
    }

    return 0;
}