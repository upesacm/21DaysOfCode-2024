#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct {
    int u, v, weight;
} Edge;

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void union_set(int parent[], int rank[], int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);

    if (rank[x_root] < rank[y_root])
        parent[x_root] = y_root;
    else if (rank[x_root] > rank[y_root])
        parent[y_root] = x_root;
    else {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int A[MAX_N];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    Edge edges[MAX_N * (MAX_N - 1) / 2];
    int edge_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int weight = abs(i * j - A[i] % A[j] - A[j] % A[i]);
            edges[edge_count].u = i;
            edges[edge_count].v = j;
            edges[edge_count].weight = weight;
            edge_count++;
        }
    }

    qsort(edges, edge_count, sizeof(Edge), compare);

    int parent[MAX_N];
    int rank[MAX_N];

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_cost = 0;
    int mst_edges = 0;

    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            mst_cost += edges[i].weight;
            mst_edges++;
            union_set(parent, rank, u, v);

            if (mst_edges == N - 1)
                break;
        }
    }

    printf("%d\n", mst_cost);

    return 0;
}