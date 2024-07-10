#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

AdjList graph[MAX_NODES];
int visited[MAX_NODES];
int distance[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = graph[v].head;
    graph[v].head = newNode;
}

void bfs(int start) {
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    Node* queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    distance[start] = 0;

    while (front < rear) {
        int curr = queue[front++];
        Node* temp = graph[curr].head;
        while (temp != NULL) {
            if (!visited[temp->data]) {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
                distance[temp->data] = distance[curr] + 1;
            }
            temp = temp->next;
        }
    }
}

void printShortestReach(int start, int numNodes) {
    printf("Shortest reach from node %d:\n", start);
    for (int i = 0; i < numNodes; i++) {
        if (i != start) {
            printf("Node %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    scanf("%d", &start);

    bfs(start);
    printShortestReach(start, numNodes);

    return 0;
}