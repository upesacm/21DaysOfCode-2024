//Important Graph

//using Kruskal algo.
//author - Ayush Dey

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int *parent, int i) {
if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];}

void union_set(int *parent, int *rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
     if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }}}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
 }

Edge *edges = (Edge *)malloc(n * n * sizeof(Edge));
int e = 0;
for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = abs((i + 1) * (j + 1) - a[i] % a[j] - a[j] % a[i]);
            edges[e++] = (Edge){i, j, weight};
        } }

qsort(edges, e, sizeof(Edge), cmp);

int *parent = (int *)malloc(n * sizeof(int));
int *rank = (int *)calloc(n, sizeof(int));
for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

int mst_cost = 0;
for (int i = 0; i < e; i++) {
int u = edges[i].u;
int w = edges[i].w;
    int v = edges[i].v;
    if (find(parent, u) != find(parent, v)) {
            mst_cost += w;
            union_set(parent, rank, u, v);
        }}
printf("%d\n", mst_cost);

free(a);
free(edges);
free(parent);
free(rank);
return 0;
}
