#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
int calculateWeight(int x, int y, int A[]) {
    return abs(x * y - A[x - 1] % A[y - 1] - A[y - 1] % A[x - 1]);
}

int find(int parent[], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int edges[N * (N - 1) / 2][3];
    int edgeCount = 0;
    int parent[N + 1];
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int weight = calculateWeight(i, j, A);
            edges[edgeCount][0] = weight;
            edges[edgeCount][1] = i;
            edges[edgeCount][2] = j;
            edgeCount++;
        }
    }
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][0] > edges[j + 1][0]) {
                int tempWeight = edges[j][0];
                int tempNode1 = edges[j][1];
                int tempNode2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = tempWeight;
                edges[j + 1][1] = tempNode1;
                edges[j + 1][2] = tempNode2;
            }
        }
    }
    int minCost = 0;
    for (int i = 0; i < edgeCount; i++) {
        int x = edges[i][1];
        int y = edges[i][2];
        int xset = find(parent, x);
        int yset = find(parent, y);

        if (xset != yset) {
            minCost += edges[i][0];
            unionSets(parent, xset, yset);
        }
    }

    printf("%d\n", minCost);

    return 0;
}
