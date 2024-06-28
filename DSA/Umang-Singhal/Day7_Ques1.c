#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findMinCost(int* station, int n, int p) {
    qsort(station, n, sizeof(int), compare);
    int cost = 0;
    int pos = 0;
    
    for (int i = 0; i < p; ++i) {
        while (pos < n - 1 && abs(station[pos + 1] - i) < abs(station[pos] - i)) {
            ++pos;
        }
        cost += abs(station[pos] - i);
    }
    
    return cost;
}

int main() {
    int n, p;
    printf("Enter the number of police stations: ");
    scanf("%d", &n);
    
    int* station = (int*)malloc(n * sizeof(int));
    printf("Enter the positions of police stations:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &station[i]);
    }
    
    printf("Enter the number of properties to buy: ");
    scanf("%d", &p);
    
    int result = findMinCost(station, n, p);
    printf("The minimum amount required to buy %d properties is %d\n", p, result);
    
    free(station);
    return 0;
}
