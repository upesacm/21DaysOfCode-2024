#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

void bfs(int graph[][MAX_NODES], int start, int num_nodes) {
    int visited[MAX_NODES] = {0};
    int distance[MAX_NODES] = {0};

    Queue q;
    q.front = q.rear = NULL;

    enqueue(&q, start);
    visited[start] = 1;

    while (q.front != NULL) {
        int node = dequeue(&q);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
                distance[i] = distance[node] + 1;
            }
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Shortest reach from %d to %d: %d\n", start, i, distance[i]);
    }
}

int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the edges:\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    bfs(graph, start, num_nodes);

    return 0;
}
