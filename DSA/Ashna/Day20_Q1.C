#include <stdio.h>
#include <stdlib.h>

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

int isQueueEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
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

int isBipartite(int n, Node** adj) {
    int* color = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    
    Queue* queue = createQueue(n + 1);
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            enqueue(queue, i);
            
            while (!isQueueEmpty(queue)) {
                int u = dequeue(queue);
                
                Node* temp = adj[u];
                while (temp) {
                    int v = temp->vertex;
                    
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        enqueue(queue, v);
                    } else if (color[v] == color[u]) {
                        free(queue->items);
                        free(queue);
                        free(color);
                        return 0; // Not bipartite
                    }
                    
                    temp = temp->next;
                }
            }
        }
    }
    
    free(queue->items);
    free(queue);
    free(color);
    
    return 1; // Bipartite
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
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
    
    if (isBipartite(n, adj)) {
        printf("YES\n");
    } else {
        printf("NO\n");
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
    
    return 0;
}
