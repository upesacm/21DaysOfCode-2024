#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
int isBipartiteUtil(int node, int c, int numNodes) {
    color[node] = c;
    for (int i = 1; i <= numNodes; i++) {
        if (graph[node][i]) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(i, 1 - c, numNodes)) {
                    return 0;
                }
            } else if (color[i] == color[node]) {
                return 0;
            }
        }
    }

    return 1;
}

int isBipartite(int numNodes) {
    for (int i = 1; i <= numNodes; i++) {
        color[i] = -1;
    }

    for (int i = 1; i <= numNodes; i++) {
        if (color[i] == -1) {
            if (!isBipartiteUtil(i, 0, numNodes)) {
                return 0;
            }
        }
    }

    return 1;
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
    }
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    if (isBipartite(numNodes)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
