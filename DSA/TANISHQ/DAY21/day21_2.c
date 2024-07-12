#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int N;
int A[MAX_N];
int parent[MAX_N][MAX_N];
int depth[MAX_N];

void dfs(int node, int par, int d) {
    depth[node] = d;
    for (int i = 1; i <= N; i++) {
        if (parent[node][i] && i != par) {
            dfs(i, node, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    while (depth[u] != depth[v]) {
        u = parent[u][depth[u] - depth[v]];
    }
    while (u != v) {
        for (int i = N; i >= 1; i--) {
            if (parent[u][i] && parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
                break;
            }
        }
    }
    return u;
}

int main() {
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        parent[u][v] = parent[v][u] = 1;
    }

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    dfs(1, 0, 1);

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (A[i] == A[j]) {
                int l = lca(i, j);
                ans += depth[i] + depth[j] - 2 * depth[l];
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}