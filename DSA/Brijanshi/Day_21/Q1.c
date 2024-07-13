#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int weight;
    int u;
    int v;
} Edge;

typedef struct {
    Edge* data;
    int size;
} EdgeArray;

EdgeArray* createEdgeArray(int size) {
    EdgeArray* arr = (EdgeArray*)malloc(sizeof(EdgeArray));
    arr->data = (Edge*)malloc(size * sizeof(Edge));
    arr->size = size;
    return arr;
}

void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(EdgeArray* arr, int low, int high) {
    if (low < high) {
        int pivot = arr->data[high].weight;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr->data[j].weight < pivot) {
                i++;
                swap(&arr->data[i], &arr->data[j]);
            }
        }
        swap(&arr->data[i + 1], &arr->data[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int minimumSpanningTreeCost(int n, int arr[]) {
    EdgeArray* edges = createEdgeArray(n * (n - 1) / 2);
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges->data[k].weight = abs(arr[i] - arr[j]);
            edges->data[k].u = i;
            edges->data[k].v = j;
            k++;
        }
    }
    quickSort(edges, 0, edges->size - 1);

    int parent[n];
    int rank[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int cost = 0;
    int count = 0;
    for (int i = 0; i < edges->size; i++) {
        int x = find(parent, edges->data[i].u);
        int y = find(parent, edges->data[i].v);
        if (x != y) {
            cost += edges->data[i].weight;
            unionSet(parent, rank, x, y);
            count++;
            if (count == n - 1)
                break;
        }
    }

    free(edges->data);
    free(edges);

    return cost;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minimumSpanningTreeCost(n, arr));

    return 0;
}
