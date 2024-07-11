#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};


struct AdjList {
    struct AdjListNode *head;
};


struct Graph {
    int V;
    struct AdjList* array;
};


struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
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


void addEdge(struct Graph* graph, int src, int dest, int weight) {

    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}


int minDistance(int dist[], bool sptSet[], int V) {

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printSolution(int dist[], int V) {
    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");
}


void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V]; 

    bool sptSet[V]; 
             

  
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

 
    dist[src] = 0;


    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet, V);

 
        sptSet[u] = true;

      
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v])
                dist[v] = dist[u] + pCrawl->weight;

            pCrawl = pCrawl->next;
        }
    }

    printSolution(dist, V);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &vertices, &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges with their weights (u v w):\n");
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u - 1, v - 1, weight); 
    }

    int start;
    printf("Enter the starting node:\n");
    scanf("%d", &start);

    dijkstra(graph, start - 1); 

    for (int i = 0; i < vertices; ++i) {
        struct AdjListNode* node = graph->array[i].head;
        while (node != NULL) {
            struct AdjListNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}
