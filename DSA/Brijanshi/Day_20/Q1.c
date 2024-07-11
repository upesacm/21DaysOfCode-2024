#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

bool graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
bool color[MAX_VERTICES];

bool dfs(int vertex, bool c) {
    visited[vertex] = true;
    color[vertex] = c;

    for (int i = 1; i <= MAX_VERTICES; i++) {
        if (graph[vertex][i] && !visited[i]) {
            if (!dfs(i, !c)) return false;
        } else if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }

    return true;
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    for (int i = 1; i <= vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = true;
    }

    bool possible = true;
    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            possible = dfs(i, true);
            if (!possible) break;
        }
    }

    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}
