#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int pos;
    int cost;
} Property;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareProperty(const void *a, const void *b) {
    return (((Property*)a)->cost - ((Property*)b)->cost);
}

long long findMinCost(int* station, int n, int p) {
    qsort(station, n, sizeof(int), compare);

    long long totalCost = 0;
    int count = 0;
    int i;


    Property *heap = (Property*)malloc(2 * n * sizeof(Property));
    int heapSize = 0;

    for (i = 0; i < n; ++i) {
        heap[heapSize++] = (Property){station[i] - 1, 1}; 
        heap[heapSize++] = (Property){station[i] + 1, 1}; 
    }


    qsort(heap, heapSize, sizeof(Property), compareProperty);

    while (count < p) {
        Property current = heap[0];


        for (i = 1; i < heapSize; ++i) {
            heap[i - 1] = heap[i];
        }
        heapSize--;

        totalCost += current.cost;
        count++;

        heap[heapSize++] = (Property){current.pos - 1, current.cost + 1};
        heap[heapSize++] = (Property){current.pos + 1, current.cost + 1};


        qsort(heap, heapSize, sizeof(Property), compareProperty);
    }

    free(heap);
    return totalCost;
}

int main() {
    int n, p;
    printf("Enter the number of police stations: ");
    scanf("%d", &n);

    int *station = (int*)malloc(n * sizeof(int));
    printf("Enter the positions of the police stations: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &station[i]);
    }

    printf("Enter the number of properties to buy: ");
    scanf("%d", &p);

    long long result = findMinCost(station, n, p);
    printf("%lld\n", result);

    free(station);
    return 0;
}
