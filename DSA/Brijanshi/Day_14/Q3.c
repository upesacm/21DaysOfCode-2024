#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int hallway[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &hallway[i]);
    }
    int bulbs = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (hallway[i]!= -1) {
            if (last < i - hallway[i]) {
                bulbs++;
                last = i + hallway[i];
            }
        }
    }
    if (last < n - 1) {
        printf("-1\n");
    } else {
        printf("%d\n", bulbs);
    }
    return 0;
}
