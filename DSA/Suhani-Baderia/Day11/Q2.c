#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} priority_queue;

priority_queue* create(int capacity) {
    priority_queue* pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->arr = (int*)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void insert(priority_queue* pq, int element) {
    if (pq->size == pq->capacity) {
        printf("Priority queue is full\n");
        return;
    }
    pq->arr[pq->size] = element;
    int i = pq->size;
    pq->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->arr[parent] <= pq->arr[i]) break;
        int temp = pq->arr[parent];
        pq->arr[parent] = pq->arr[i];
        pq->arr[i] = temp;
        i = parent;
    }
}

int extract(priority_queue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int min = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < pq->size && pq->arr[left] < pq->arr[smallest]) smallest = left;
        if (right < pq->size && pq->arr[right] < pq->arr[smallest]) smallest = right;
        if (smallest == i) break;
        int temp = pq->arr[smallest];
        pq->arr[smallest] = pq->arr[i];
        pq->arr[i] = temp;
        i = smallest;
    }
    return min;
}

int main() {
    priority_queue* pq = create(10);
    insert(pq, 4);
    insert(pq, 2);
    printf("%d\n", extract(pq)); 
    printf("%d\n", extract(pq)); 
    return 0;
}
