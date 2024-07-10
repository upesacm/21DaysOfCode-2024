#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj[MAX_NODES][MAX_NODES];
int adjCount[MAX_NODES];
int distances[MAX_NODES];

void bfs(int startNode, int numNodes) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    
    for (int i = 0; i <= numNodes; i++) {
        distances[i] = -1;
    }
    
    queue[rear++] = startNode;
    distances[startNode] = 0;
    
    while (front < rear) {
        int node = queue[front++];
        
        for (int i = 0; i < adjCount[node]; i++) {
            int neighbor = adj[node][i];
            
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                queue[rear++] = neighbor;
            }
        }
    }
}

int main() {
    int numNodes, numEdges, startNode;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
   
    for (int i = 0; i <= numNodes; i++) {
        adjCount[i] = 0;
    }
    
    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        adj[node1][adjCount[node1]++] = node2;
        adj[node2][adjCount[node2]++] = node1;
    }
    
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    
    bfs(startNode, numNodes);
    
    printf("Shortest distances from node %d:\n", startNode);
    for (int i = 1; i <= numNodes; i++) {
        printf("Node %d: %d\n", i, distances[i]);
    }
    
    return 0;
}
