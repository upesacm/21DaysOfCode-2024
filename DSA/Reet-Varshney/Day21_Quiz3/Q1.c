#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
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
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    int numEdges = N * (N - 1) / 2;
    Edge edges[numEdges];
    int index = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int weight = abs(i * j - A[i] % A[j] - A[j] % A[i]);
            edges[index++] = (Edge){i, j, weight};
        }
    }

    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    int parent[N + 1], rank[N + 1];
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstCost = 0;
    int edgesUsed = 0;

    for (int i = 0; i < numEdges && edgesUsed < N - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            mstCost += weight;
            unionSets(parent, rank, rootU, rootV);
            edgesUsed++;
        }
    }

    printf("%d\n", mstCost);

    return 0;
}
