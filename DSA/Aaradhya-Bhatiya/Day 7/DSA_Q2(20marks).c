#include <stdio.h>
#include <string.h>
#include <math.h>

int minCost(char *str) {
    int len = strlen(str);

    int totalX = 0, totalY = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'x') {
            totalX++;
        } else {
            totalY++;
        }
    }

    int minCost = totalY;
    int currentX = 0, currentY = 0;

    for (int i = 0, j = len - 1; i < len && j >= 0; i++, j--) {
        if (str[i] == 'x') {
            currentX++;
        } else {
            currentY++;
        }

        int potentialCost = fmax(totalX - currentX, currentY);

        if (minCost > potentialCost) {
            minCost = potentialCost;
        }
    }

    return minCost;
}

int main() {
    char str[500];
    scanf("%s", str);

    int result = minCost(str);
    printf("%d", result);

    return 0;
}