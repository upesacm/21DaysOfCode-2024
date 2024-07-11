#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

int nodes, edges;
int adj[MAX_NODES][MAX_NODES];
int nodeColor[MAX_NODES];

bool isBipartite(int node, int color) {
    nodeColor[node] = color;
    for (int i = 1; i <= nodes; i++) {
        if (adj[node][i] == 1 && nodeColor[i] == color) {
            return false;
        }
        if (adj[node][i] == 1 && nodeColor[i] == 0) {
            if (!isBipartite(i, 3 - color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &nodes, &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 1; i <= nodes; i++) {
        nodeColor[i] = 0;
    }

    for (int i = 1; i <= nodes; i++) {
        if (nodeColor[i] == 0) {
            if (!isBipartite(i, 1)) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}
