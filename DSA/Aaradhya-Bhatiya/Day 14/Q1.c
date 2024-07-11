#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

int minMoves(int heights[], int n) {
    int moves = 0;
    int newArr[MAX];
    int newArrSize;
    
    while (1) {
        int i, j = 0;
        int moveOccurred = 0;

        for (i = 1; i < n; i++) {
            if (heights[i - 1] > heights[i]) {
                moveOccurred = 1;
                break;
            }
        }
        if (!moveOccurred) {
            break;
        }

        newArrSize = 0;
        for (i = 0; i < n; i++) {
            if (i == 0 || heights[i] >= heights[i - 1]) {
                newArr[newArrSize++] = heights[i];
            }
        }

        for (i = 0; i < newArrSize; i++) {
            heights[i] = newArr[i];
        }
        n = newArrSize;
        moves++;
    }

    return moves;
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int result = minMoves(heights, n);
    printf("%d", result);

    return 0;
}
