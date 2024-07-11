#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode *head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

bool isBipartite(struct Graph* graph, int src, int* colorArr) {
    colorArr[src] = 1;

    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = src;

    while (front != rear) {
        int u = queue[front++];

        struct AdjListNode* temp = graph->array[u].head;
        while (temp) {
            int v = temp->dest;

            if (v == u) {
                return false;
            }

            if (colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                queue[rear++] = v;
            } else if (colorArr[v] == colorArr[u]) {
                return false;
            }
            temp = temp->next;
        }
    }

    return true;
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < E; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1);  
    }

    int colorArr[MAX_VERTICES];
    for (int i = 0; i < V; ++i) {
        colorArr[i] = -1;
    }

    bool result = true;
    for (int i = 0; i < V; ++i) {
        if (colorArr[i] == -1) {
            if (!isBipartite(graph, i, colorArr)) {
                result = false;
                break;
            }
        }
    }

    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
