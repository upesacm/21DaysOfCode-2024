#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct {
    int node;
    int distance;
} QueueNode;

typedef struct {
    QueueNode data[MAX_NODES];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int node, int distance) {
    q->data[q->rear].node = node;
    q->data[q->rear].distance = distance;
    q->rear++;
}

QueueNode dequeue(Queue* q) {
    QueueNode node = q->data[q->front];
    q->front++;
    return node;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void bfs(int n, int graph[n][n], int start, int distances[n]) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distances[i] = -1;
    }
    
    Queue q;
    q.front = q.rear = 0;

    enqueue(&q, start, 0);
    visited[start] = true;
    distances[start] = 0;

    while (!isEmpty(&q)) {
        QueueNode current = dequeue(&q);
        int currentNode = current.node;
        int currentDistance = current.distance;

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                enqueue(&q, i, currentDistance + 1);
                visited[i] = true;
                distances[i] = currentDistance + 1;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (node pairs):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    int distances[n];
    bfs(n, graph, start, distances);

    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("Node %d: %d\n", i, distances[i]);
        }
    }

    return 0;
}
