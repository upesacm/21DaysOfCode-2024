#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 100

int N;
int edges[MAX_N][MAX_N]; 
int A[MAX_N];

void initializeEdges() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            edges[i][j] = 0;
        }
    }
}

int bfs(int start, int end) {
    int visited[MAX_N] = {0};
    int queue[MAX_N];
    int front = 0, rear = 0;
    int distance[MAX_N] = {0};
    
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        
        if (current == end) {
            return distance[end];
        }

        for (int i = 1; i <= N; i++) {
            if (edges[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
                distance[i] = distance[current] + 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    
    initializeEdges();
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    
    int totalSum = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (A[i] == A[j]) {
                totalSum += bfs(i, j);
            }
        }
    }
    
    printf("%d\n", totalSum);
    
    return 0;
}
