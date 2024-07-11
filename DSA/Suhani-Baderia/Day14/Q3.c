#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int minMoves(int n, int height[]) {
    int moves = 0;
    int i = 0;
    while (i < n - 1) {
        if (height[i] > height[i + 1]) {
            moves++;
            i++;
            while (i < n - 1 && height[i] < height[i - 1]) {
                i++;
            }
        } else {
            i++;
        }
    }
    return moves;
}

int main() {
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    printf("%d\n", minMoves(n, height));
    return 0;
}
