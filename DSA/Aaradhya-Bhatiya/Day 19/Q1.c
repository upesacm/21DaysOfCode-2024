#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define INF -1

typedef struct {
    int node;
    int distance;
} QueueNode;

typedef struct {
    QueueNode *data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (QueueNode*)malloc(size * sizeof(QueueNode));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, int node, int distance) {
    queue->rear++;
    queue->data[queue->rear].node = node;
    queue->data[queue->rear].distance = distance;
    queue->size++;
}

QueueNode dequeue(Queue* queue) {
    QueueNode item = queue->data[queue->front];
    queue->front++;
    queue->size--;
    return item;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void bfs(int start, int n, int adjMatrix[][MAX_NODES], int distances[]) {
    Queue* queue = createQueue(n);
    int visited[MAX_NODES] = {0};
    for (int i = 0; i < n; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;
    visited[start] = 1;
    enqueue(queue, start, 0);

    while (!isEmpty(queue)) {
        QueueNode current = dequeue(queue);
        int node = current.node;
        int distance = current.distance;

        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] && !visited[i]) {
                distances[i] = distance + 1;
                visited[i] = 1;
                enqueue(queue, i, distances[i]);
            }
        }
    }

    free(queue->data);
    free(queue);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};
    int distances[MAX_NODES];

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int start;
    scanf("%d", &start);

    bfs(start, n, adjMatrix, distances);

    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("%d ", distances[i]);
        }
    }
    printf("\n");

    return 0;
}
