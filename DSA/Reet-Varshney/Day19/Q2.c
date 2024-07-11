#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

void traverseGraph(int adjacencyMatrix[][MAX_NODES], int numVertices, int currentNode, int visited[]) {
    visited[currentNode] = 1;
    printf("%d ", currentNode);

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            traverseGraph(adjacencyMatrix, numVertices, i, visited);
        }
    }
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);

    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjacencyMatrix[u][v] = adjacencyMatrix[v][u] = 1;
    }
    int startVertex;
    scanf("%d", &startVertex);

    int visited[MAX_NODES] = {0};

    printf("Depth-First Traversal: ");
    traverseGraph(adjacencyMatrix, numVertices, startVertex, visited);
    printf("\n");

    return 0;
}
