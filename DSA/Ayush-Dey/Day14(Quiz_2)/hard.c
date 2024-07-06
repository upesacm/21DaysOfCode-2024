//Light Up the Hall

#include <stdio.h>
#include <stdlib.h>

int minBulbs(int n, int* hallway) {
    if (n == 0) return -1;
    
    // a special case maybe there like if n == 1 and hallway[0] == -1, that's impossible
    if (n == 1 && hallway[0] == -1) return -1;
    
    
    int* maxReach = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        maxReach[i] = -1;
    }
    
    for (int i = 0; i < n; ++i) {
        if (hallway[i] >= 0) {
            int start = i - hallway[i];
            int end = i + hallway[i];
            if (start < 0) start = 0;
            if (end >= n) end = n - 1;
            maxReach[start] = end;
        }
    }
    
    // greedy approach

    int bulbs = 0;
    int i = 0;
    while (i < n) {
        if (maxReach[i] == -1) {
            return -1; 
        }
        
        int furthest = maxReach[i];
        bulbs++;
        i = furthest + 1;
    }
    
    free(maxReach);
    return bulbs;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* hallway = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &hallway[i]);
    }
    
    int result = minBulbs(n, hallway);
    printf("%d\n", result);
    
    free(hallway);
    return 0;
}
