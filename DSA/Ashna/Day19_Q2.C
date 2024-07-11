#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Stack {
    int* items;
    int top;
    int size;
} Stack;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == s->size - 1) return;
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->items[(s->top)--];
}

void addEdge(Node** adj, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int n, Node** adj, int start) {
    int* visited = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    
    Stack* stack = createStack(n + 1);
    push(stack, start);
    
    while (!isStackEmpty(stack)) {
        int current = pop(stack);
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;
        }
        Node* temp = adj[current];
        while (temp) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                push(stack, neighbor);
            }
            temp = temp->next;
        }
    }
    
    free(stack->items);
    free(stack);
    free(visited);
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
    
    printf("Nodes visited in DFS order from node %d:\n", start);
    dfs(n, adj, start);
    printf("\n");
    
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
