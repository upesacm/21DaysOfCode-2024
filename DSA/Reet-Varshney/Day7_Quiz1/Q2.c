#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int minCost(char *inputStr) {
    int left = 0;
    int right = strlen(inputStr) - 1;
    int yCount = 0;

    while (left < right && inputStr[left] == 'y') {
        yCount++;
        left++;
    }

    while (right > left && inputStr[right] == 'y') {
        yCount++;
        right--;
    }

    return yCount;
}

int main() {

    char string[100005];
    scanf("%s", string);
    
    int result = minCost(string);
    printf("%d\n", result);

    return 0;
}
