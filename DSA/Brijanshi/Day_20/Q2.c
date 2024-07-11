#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct {
    int u, v, weight;
} Edge;

int vertices, edges;
Edge edge_list[MAX_VERTICES * MAX_VERTICES];
int distance[MAX_VERTICES];
int previous[MAX_VERTICES];

void dijkstra(int start) {
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
        previous[i] = -1;
    }

    distance[start] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < vertices; j++) {
            if (distance[j] < min_distance) {
                min_distance = distance[j];
                min_index = j;
            }
        }

        for (int j = 0; j < edges; j++) {
            if (edge_list[j].u == min_index) {
                int v = edge_list[j].v;
                int weight = edge_list[j].weight;

                if (distance[min_index] + weight < distance[v]) {
                    distance[v] = distance[min_index] + weight;
                    previous[v] = min_index;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edge_list[i].u, &edge_list[i].v, &edge_list[i].weight);
    }

    int start;
    scanf("%d", &start);

    dijkstra(start - 1); // subtract 1 because vertex indices are 0-based

    for (int i = 0; i < vertices; i++) {
        printf("%d ", distance[i]);
    }
    printf("\n");

    return 0;
}
