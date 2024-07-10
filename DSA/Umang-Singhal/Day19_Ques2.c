#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; 
int visited[MAX_NODES]; 
int result[MAX_NODES];  
int resultIndex = 0;

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfsHelper(int node, int numNodes) {
    visited[node] = 1;
    result[resultIndex++] = node;

    for (int i = 1; i <= numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfsHelper(i, numNodes);
        }
    }
}

void dfs(int startNode, int numNodes) {
    dfsHelper(startNode, numNodes);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i <= numNodes; i++) {
        for (int j = 0; j <= numNodes; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);

   
    dfs(startNode, numNodes);

  
    printf("DFS traversal starting from node %d: ", startNode);
    for (int i = 0; i < resultIndex; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
