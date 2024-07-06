#include <stdio.h>
#include <stdlib.h>

int minBulbs(int n, int* hallway) {
    int count = 0;
    int i = 0;
    
    while (i < n) {
        if (hallway[i] == -1) {
            i++;
            continue;
        }

        int furthest = i + hallway[i];

        if (furthest >= n)
            furthest = n - 1;

        count++;

        i = furthest + 1;
    }
    
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *hallway = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &hallway[i]);
    }
    
    int result = minBulbs(n, hallway);
    
    for (int i = 0; i < n; i++) {
        if (hallway[i] == -1) {
            printf("-1\n");
            free(hallway);
            return 0;
        }
    }
    
    printf("%d\n", result);
    
    free(hallway);
    
    return 0;
}
