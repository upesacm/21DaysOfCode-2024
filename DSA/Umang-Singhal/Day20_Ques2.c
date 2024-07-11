#include <stdio.h>
#include <limits.h>
#define MAX_NODES 100
#define INF INT_MAX
int graph[MAX_NODES][MAX_NODES]; 
int dist[MAX_NODES];  
int visited[MAX_NODES];
int minDistance(int numNodes) {
    int min = INF, min_index;
    for (int v = 1; v <= numNodes; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int startNode, int numNodes) {
    for (int i = 1; i <= numNodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[startNode] = 0;
    for (int count = 1; count <= numNodes - 1; count++) {
        int u = minDistance(numNodes);
        visited[u] = 1;
        for (int v = 1; v <= numNodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; 
    }
    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    dijkstra(startNode, numNodes);
    printf("Shortest path distances from node %d:\n", startNode);
    for (int i = 1; i <= numNodes; i++) {
        if (dist[i] == INF) {
            printf("Node %d: INF\n", i);
        } else {
            printf("Node %d: %d\n", i, dist[i]);
        }
    }
    return 0;
}
