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

void addToQueue(Queue* q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int removeFromQueue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    int data = q->front->data;
    Node* node = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(node);
    return data;
}

void findShortestReach(int graph[][MAX_NODES], int numNodes, int startNode) {
    int visited[MAX_NODES] = {0};
    int distances[MAX_NODES] = {0};

    Queue queue;
    queue.front = queue.rear = NULL;

    addToQueue(&queue, startNode);
    visited[startNode] = 1;

    while (queue.front != NULL) {
        int currentNode = removeFromQueue(&queue);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                addToQueue(&queue, i);
                visited[i] = 1;
                distances[i] = distances[currentNode] + 1;
            }
        }
    }

    for (int i = 0; i < numNodes; i++) {
        printf("Shortest reach from node %d to node %d: %d\n", startNode, i, distances[i]);
    }
}

int main() {
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);

    int graph[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int start;
    scanf("%d", &start);

    findShortestReach(graph, numNodes, start);

    return 0;
}
