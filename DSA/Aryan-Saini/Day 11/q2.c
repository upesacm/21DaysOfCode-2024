#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyDown(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest])
        smallest = left;

    if (right < pq->size && pq->data[right] < pq->data[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&pq->data[i], &pq->data[smallest]);
        heapifyDown(pq, smallest);
    }
}

void heapifyUp(PriorityQueue *pq, int i) {
    if (i && pq->data[(i - 1) / 2] > pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        heapifyUp(pq, (i - 1) / 2);
    }
}

void insert(PriorityQueue *pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue overflow\n");
        return;
    }

    pq->data[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

int extractMin(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority Queue underflow\n");
        return INT_MAX;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->data[0];
    }

    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);

    return root;
}

int main() {
    PriorityQueue pq;
    pq.size = 0;

    insert(&pq, 4);
    insert(&pq, 2);
    printf("Extracted min: %d\n", extractMin(&pq));
    printf("Extracted min: %d\n", extractMin(&pq));

    return 0;
}
