#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} QNode;

typedef struct {
    QNode *nodes;
    int front, rear, capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->nodes = (QNode*)malloc(capacity * sizeof(QNode));
    q->front = q->rear = -1;
    q->capacity = capacity;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int node, int dist) {
    if (q->rear == q->capacity - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->rear++;
    q->nodes[q->rear].node = node;
    q->nodes[q->rear].dist = dist;
}

QNode dequeue(Queue *q) {
    QNode n = { -1, -1 };
    if (isEmpty(q)) return n;
    n = q->nodes[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return n;
}

void addEdge(int **adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void bfs(int **adj, int n, int start) {
    int *dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    Queue q;
    initQueue(&q, n);
    enqueue(&q, start, 0);

    while (!isEmpty(&q)) {
        QNode cur = dequeue(&q);
        for (int i = 0; i < n; i++) {
            if (adj[cur.node][i] && dist[i] == INT_MAX) {
                dist[i] = cur.dist + 1;
                enqueue(&q, i, dist[i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != start) {
            if (dist[i] == INT_MAX) printf("-1 ");
            else printf("%d ", dist[i]);
        }
    }
    printf("\n");

    free(dist);
    free(q.nodes);
}

int main() {
    int n, m, u, v, start;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int **adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u - 1, v - 1);
    }

    printf("Enter starting node: ");
    scanf("%d", &start);
    
    bfs(adj, n, start - 1);

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
