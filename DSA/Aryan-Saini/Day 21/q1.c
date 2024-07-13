#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int calculate_weight(int x, int y, int A[]) {
    return abs(x * y - A[x - 1] % A[y - 1] - A[y - 1] % A[x - 1]);
}

int kruskal(int N, int A[]) {
    int edgeCount = N * (N - 1) / 2;
    Edge edges[edgeCount];
    int k = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            edges[k].u = i;
            edges[k].v = j;
            edges[k].weight = calculate_weight(i, j, A);
            k++;
        }
    }
    qsort(edges, edgeCount, sizeof(Edge), compare);

    int parent[N + 1], rank[N + 1];
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstCost = 0, edgesUsed = 0;
    for (int i = 0; i < edgeCount && edgesUsed < N - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(parent, u) != find(parent, v)) {
            unite(parent, rank, u, v);
            mstCost += weight;
            edgesUsed++;
        }
    }

    return mstCost;
}

int main() {
    int N;
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);

    int A[N];
    printf("Enter the elements of the array A: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = kruskal(N, A);
    printf("The cost of the minimum spanning tree is: %d\n", result);

    return 0;
}
