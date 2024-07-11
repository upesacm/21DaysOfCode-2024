#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

int vertices, edges;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES]; // 0: uncolored, 1: color 1, 2: color 2

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] == 1) {
            if (color[i] == c) return false; // adjacent vertices have same color
            if (color[i] == 0 && !dfs(i, 3 - c)) return false; // recursive call
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &vertices, &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // undirected graph
    }

    for (int i = 0; i < vertices; i++) color[i] = 0; // initialize colors

    bool is_bipartite = true;
    for (int i = 0; i < vertices; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                is_bipartite = false;
                break;
            }
        }
    }

    printf("%s\n", is_bipartite ? "YES" : "NO");
    return 0;
}