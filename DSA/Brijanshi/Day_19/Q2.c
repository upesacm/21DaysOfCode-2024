#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

void dfs(int graph[][MAX_NODES], int start, int num_nodes, bool visited[]) {
    printf("%d ", start);
    visited[start] = true;

    for (int i = 0; i < num_nodes; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i, num_nodes, visited);
        }
    }
}

int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the edges:\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    bool visited[MAX_NODES] = {false};

    printf("DFS order: ");
    dfs(graph, start, num_nodes, visited);
    printf("\n");

    return 0;
}
