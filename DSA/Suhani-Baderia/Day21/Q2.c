#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 1001

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v) {
    Node* node = createNode(v);
    node->next = adjList[u];
    adjList[u] = node;
    node = createNode(u);
    node->next = adjList[v];
    adjList[v] = node;
}

int bfs(Node* adjList[], int start, int target, int n) {
    int visited[MAXN] = {0};
    int queue[MAXN];
    int distance[MAXN] = {0};
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        Node* temp = adjList[current];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                distance[adjVertex] = distance[current] + 1;
                queue[rear++] = adjVertex;

                if (adjVertex == target) {
                    return distance[adjVertex];
                }
            }
            temp = temp->next;
        }
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* adjList[MAXN];
    for (int i = 1; i <= N; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    int A[MAXN];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (A[i] == A[j]) {
                result += bfs(adjList, i, j, N);
            }
        }
    }

    printf("%lld\n", result);

    for (int i = 1; i <= N; i++) {
        Node* temp = adjList[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}
