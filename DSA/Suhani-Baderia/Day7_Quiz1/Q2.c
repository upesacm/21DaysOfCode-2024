#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calculateMinCost(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    int y_count = 0;

    while (left < right && str[left] == 'y') {
        y_count++;
        left++;
    }

    while (right > left && str[right] == 'y') {
        y_count++;
        right--;
    }

    return y_count;
}

int main() {

    char str[100005];
    scanf("%s", str);
    
    int result = calculateMinCost(str);
    printf("%d\n", result);

    return 0;
}
