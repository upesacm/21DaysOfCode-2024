#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int v;
    int *adj[MAX];
    int deg[MAX];
} Graph;

void initGraph(Graph *g, int n) {
    g->v = n;
    for (int i = 0; i < n; i++) {
        g->deg[i] = 0;
        g->adj[i] = (int *)malloc(n * sizeof(int));
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][g->deg[u]++] = v;
    g->adj[v][g->deg[v]++] = u;
}

int bfs(Graph *g, int start, int *color) {
    int q[MAX], front = 0, rear = 0;
    q[rear++] = start;
    color[start] = 0;
    while (front < rear) {
        int cur = q[front++];
        for (int i = 0; i < g->deg[cur]; i++) {
            int next = g->adj[cur][i];
            if (color[next] == -1) {
                color[next] = 1 - color[cur];
                q[rear++] = next;
            } else if (color[next] == color[cur]) {
                return 0;
            }
        }
    }
    return 1;
}

int isBipartite(Graph *g) {
    int color[MAX];
    for (int i = 0; i < g->v; i++) color[i] = -1;
    for (int i = 0; i < g->v; i++) {
        if (color[i] == -1) {
            if (!bfs(g, i, color)) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    Graph g;
    initGraph(&g, n);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u - 1, v - 1);
    }

    if (isBipartite(&g)) printf("YES\n");
    else printf("NO\n");

    for (int i = 0; i < n; i++) free(g.adj[i]);

    return 0;
}
