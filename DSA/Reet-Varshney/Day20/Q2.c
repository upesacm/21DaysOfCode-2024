#include <stdio.h>
#include <limits.h>

#define MAX_NODES 1000

int nodes, edges;
int weights[MAX_NODES][MAX_NODES];
int shortestPath[MAX_NODES];

void findShortestPaths(int startNode) {
    for (int i = 0; i < nodes; i++) {
        shortestPath[i] = INT_MAX;
    }
    shortestPath[startNode] = 0;

    int visited[MAX_NODES];
    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < nodes; i++) {
        int minDist = INT_MAX;
        int minIndex;
        for (int j = 0; j < nodes; j++) {
            if (!visited[j] && shortestPath[j] < minDist) {
                minDist = shortestPath[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;

        for (int j = 0; j < nodes; j++) {
            if (!visited[j] && weights[minIndex][j]!= 0 && shortestPath[minIndex] + weights[minIndex][j] < shortestPath[j]) {
                shortestPath[j] = shortestPath[minIndex] + weights[minIndex][j];
            }
        }
    }
}

int main() {
    scanf("%d %d", &nodes, &edges);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        weights[u][v] = weights[v][u] = w; 
    }

    int start;
    scanf("%d", &start);

    findShortestPaths(start);

    for (int i = 0; i < nodes; i++) {
        printf("%d ", shortestPath[i]);
    }
    printf("\n");

    return 0;
}
