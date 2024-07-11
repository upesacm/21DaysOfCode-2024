// Distance Summation

//DFS & LCA
//Author - Ayush Dey
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200002
#define LOG 18 

typedef struct Edge {
int to;
struct Edge *next;
} Edge;

Edge *adj[MAXN];
int a[MAXN];
int depth[MAXN];
int n;
int parent[MAXN][LOG];

void add_edge(int u, int v) {
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->to = v;
    e->next = adj[u];
    adj[u] = e;
}

void dfs(int node, int par, int dep) {
    depth[node] = dep;
    parent[node][0] = par;
    for (int i = 1; i < LOG; ++i) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
for (Edge *e = adj[node]; e != NULL; e = e->next) {
        if (e->to != par) {
            dfs(e->to, node, dep + 1);
        }}}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v;
        v = tmp;
    }
for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }}
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }}
    return parent[u][0];
}
int main() {
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); }

// Running DFS from an arbitrary root,choosing node 1 , here
dfs(1, 0, 0);

long long result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] == a[j]) {
                int l = lca(i, j);
                result += (depth[i] + depth[j] - 2 * depth[l]);
            }}}
 printf("%lld\n", result);
return 0;
}
