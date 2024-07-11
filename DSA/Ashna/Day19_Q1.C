#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Queue {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void addEdge(Node** adj, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int* bfs(int n, Node** adj, int start) {
    int* distance = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        distance[i] = -1;
    }
    Queue* q = createQueue(n + 1);
    distance[start] = 0;
    enqueue(q, start);
    
    while (!isEmpty(q)) {
        int current = dequeue(q);
        Node* temp = adj[current];
        while (temp) {
            int neighbor = temp->vertex;
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }
    
    free(q->items);
    free(q);
    
    return distance;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);
    
    Node** adj = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter edges (node1 node2):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    
    int* result = bfs(n, adj, start);
    printf("Shortest reach from node %d:\n", start);
    for (int i = 1; i <= n; i++) {
        if (i != start) {
            printf("Node %d: %d\n", i, result[i]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        Node* temp = adj[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
    free(result);
    
    return 0;
}
