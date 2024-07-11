#include <stdio.h>

int min_bulbs(int n, int *hallway) {
    int res = 0;
    int i = 0;
    
    while (i < n) {
        if (hallway[i] == -1) {
            return -1;
        }
        res++;
        i = i + hallway[i];
        while (i < n && hallway[i] != -1) {
            i++;
        }
    }
    
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int hallway[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &hallway[i]);
    }
    
    int result = min_bulbs(n, hallway);
    printf("%d\n", result);
    
    return 0;
}
