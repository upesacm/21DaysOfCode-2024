#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100005

typedef struct {
    int* data;
    int size;
} PriorityQueue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_init(PriorityQueue* pq) {
    pq->data = (int*)malloc(MAX_N * sizeof(int));
    pq->size = 0;
}

void pq_push(PriorityQueue* pq, int value) {
    pq->data[pq->size] = value;
    int i = pq->size;
    pq->size++;
    while (i > 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
        swap(&pq->data[(i - 1) / 2], &pq->data[i]);
        i = (i - 1) / 2;
    }
}

int pq_pop(PriorityQueue* pq) {
    int result = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;
        if (right < pq->size && pq->data[right] > pq->data[left]) {
            largest = right;
        }
        if (pq->data[i] >= pq->data[largest]) {
            break;
        }
        swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }
    return result;
}

bool pq_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    int n, m;
    
    if (scanf("%d %d", &n, &m)!= 2) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    int* indegree = (int*)calloc(n, sizeof(int));
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }
    int* adj_size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v)!= 2) {
            fprintf(stderr, "Error\n");
            return 1;
        }
        adj[u][adj_size[u]++] = v;
        indegree[v]++;
    }

    PriorityQueue pq;
    pq_init(&pq);
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            pq_push(&pq, i);
        }
    }

    int* result = (int*)malloc(n * sizeof(int));
    int result_size = 0;

    while (!pq_empty(&pq)) {
        int u = pq_pop(&pq);
        result[result_size++] = u;
        for (int i = 0; i < adj_size[u]; i++) {
            int v = adj[u][i];
            indegree[v]--;
            if (indegree[v] == 0) {
                pq_push(&pq, v);
            }
        }
    }

    if (result_size!= n) {
        printf("-1\n");
    } else {
        for (int i = result_size - 1; i >= 0; i--) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    free(pq.data);
    free(indegree);
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adj_size);
    free(result);

    return 0;
}
