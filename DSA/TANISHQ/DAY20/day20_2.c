#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct {
    int v;
    int weight;
} Edge;

int vertices, edges;
Edge graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];

void dijkstra(int start) {
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int min_dist = INT_MAX;
        int min_vertex;
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && distance[j] < min_dist) {
                min_dist = distance[j];
                min_vertex = j;
            }
        }
        visited[min_vertex] = 1;

        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && graph[min_vertex][j].weight != 0 && distance[min_vertex] + graph[min_vertex][j].weight < distance[j]) {
                distance[j] = distance[min_vertex] + graph[min_vertex][j].weight;
            }
        }
    }
}

int main() {
    scanf("%d %d", &vertices, &edges);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].v = v;
        graph[u][v].weight = w;
        graph[v][u].v = u;
        graph[v][u].weight = w; // for undirected graph
    }

    int start;
    scanf("%d", &start);

    dijkstra(start);

    printf("Shortest path distances from node %d:\n", start);
    for (int i = 0; i < vertices; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

    return 0;
}