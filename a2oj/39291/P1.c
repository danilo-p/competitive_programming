#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n > 0) {
        int i, h[n], p = 0;

        for (i = 0; i < n; i += 1) {
            scanf("%d", &h[i]);
        }

        // Check for the first element
        if (
            (h[n - 1] > h[0] && h[0] < h[1]) ||
            (h[n - 1] < h[0] && h[0] > h[1])
        ) {
            p++;
        }

        // Check for the last element
        if (
            (h[n - 2] > h[n - 1] && h[n - 1] < h[0]) ||
            (h[n - 2] < h[n - 1] && h[n - 1] > h[0])
        ) {
            p++;
        }

        // Check for the middle elements
        for (i = 1; i < n - 1; i += 1) {
            if (
                (h[i - 1] > h[i] && h[i] < h[i + 1]) ||
                (h[i - 1] < h[i] && h[i] > h[i + 1])
            ) {
                p++;
            }
        }

        printf("%d\n", p);

        scanf("%d", &n);
    }
    return 0;
}