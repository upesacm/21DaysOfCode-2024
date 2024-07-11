#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100005

typedef struct {
    int* elements;
    int count;
} CustomQueue;

void exchange(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cq_initialize(CustomQueue* cq) {
    cq->elements = (int*)malloc(MAX_N * sizeof(int));
    cq->count = 0;
}

void cq_enqueue(CustomQueue* cq, int value) {
    cq->elements[cq->count] = value;
    int i = cq->count;
    cq->count++;
    while (i > 0 && cq->elements[(i - 1) / 2] < cq->elements[i]) {
        exchange(&cq->elements[(i - 1) / 2], &cq->elements[i]);
        i = (i - 1) / 2;
    }
}

int cq_dequeue(CustomQueue* cq) {
    int result = cq->elements[0];
    cq->count--;
    cq->elements[0] = cq->elements[cq->count];
    int i = 0;
    while (2 * i + 1 < cq->count) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;
        if (right < cq->count && cq->elements[right] > cq->elements[left]) {
            largest = right;
        }
        if (cq->elements[i] >= cq->elements[largest]) {
            break;
        }
        exchange(&cq->elements[i], &cq->elements[largest]);
        i = largest;
    }
    return result;
}

bool cq_is_empty(CustomQueue* cq) {
    return cq->count == 0;
}

int main() {
    int num_nodes, num_edges;
    
    if (scanf("%d %d", &num_nodes, &num_edges) != 2) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    int* node_degrees = (int*)calloc(num_nodes, sizeof(int));
    int** adjacency_list = (int**)malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++) {
        adjacency_list[i] = (int*)malloc(num_nodes * sizeof(int));
    }
    int* adjacency_list_sizes = (int*)calloc(num_nodes, sizeof(int));

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) {
            fprintf(stderr, "Error\n");
            return 1;
        }
        adjacency_list[u][adjacency_list_sizes[u]++] = v;
        node_degrees[v]++;
    }

    CustomQueue cq;
    cq_initialize(&cq);
    
    for (int i = 0; i < num_nodes; i++) {
        if (node_degrees[i] == 0) {
            cq_enqueue(&cq, i);
        }
    }

    int* order = (int*)malloc(num_nodes * sizeof(int));
    int order_size = 0;

    while (!cq_is_empty(&cq)) {
        int u = cq_dequeue(&cq);
        order[order_size++] = u;
        for (int i = 0; i < adjacency_list_sizes[u]; i++) {
            int v = adjacency_list[u][i];
            node_degrees[v]--;
            if (node_degrees[v] == 0) {
                cq_enqueue(&cq, v);
            }
        }
    }

    if (order_size != num_nodes) {
        printf("-1\n");
    } else {
        for (int i = order_size - 1; i >= 0; i--) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }

    free(cq.elements);
    free(node_degrees);
    for (int i = 0; i < num_nodes; i++) {
        free(adjacency_list[i]);
    }
    free(adjacency_list);
    free(adjacency_list_sizes);
    free(order);

    return 0;
}
