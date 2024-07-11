#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int moves = 0;
    int i = 0;
    while (i < n - 1) {
        if (heights[i] > heights[i + 1]) {
            moves++;
            int j = i + 1;
            while (j < n && heights[j] < heights[i]) {
                j++;
            }
            for (int k = i + 1; k < n - (j - i - 1); k++) {
                heights[k] = heights[k + (j - i - 1)];
            }
            n -= (j - i - 1);
        } else {
            i++;
        }
    }

    printf("%d\n", moves);

    return 0;
}
