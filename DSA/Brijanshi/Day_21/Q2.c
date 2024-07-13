#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAXN];
int A[MAXN];

int bfs(int start, int target, int N) {
    bool visited[N+1];
    for (int i = 0; i <= N; i++)
        visited[i] = false;

    Node* queue = (Node*)malloc((N+1) * sizeof(Node));
    int front = 0, rear = 0;
    queue[rear].data = start;
    queue[rear].next = NULL;
    rear++;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front].data;
        int dist = front;
        front++;

        if (node == target) {
            free(queue);
            return dist;
        }

        Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear].data = neighbor;
                queue[rear].next = NULL;
                rear++;
            }
            temp = temp->next;
        }
    }
    free(queue);
    return 0; // Should not happen if the tree is connected
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = v;
        temp->next = adj[u];
        adj[u] = temp;

        temp = (Node*)malloc(sizeof(Node));
        temp->data = u;
        temp->next = adj[v];
        adj[v] = temp;
    }

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }

    int sum = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[i] == A[j]) {
                sum += bfs(i, j, N);
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}
