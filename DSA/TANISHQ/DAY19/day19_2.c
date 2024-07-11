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

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    Node* temp = graph[node].head;
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }
}

void dfsTraversal(int start, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");
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

    dfsTraversal(start, numNodes);

    return 0;
}