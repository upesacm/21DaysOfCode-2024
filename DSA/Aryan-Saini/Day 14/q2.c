#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 500000

typedef struct {
    int faster;
    int slower;
} Edge;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void topological_sort(int n, int adj[n][n], int indegree[n], int result[n]) {
    int queue[MAX_N], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int index = 0;
    while (front < rear) {
        int u = queue[front++];
        result[index++] = u;
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of horses (n): ");
    scanf("%d", &n);
    printf("Enter the number of pairs (m): ");
    scanf("%d", &m);
    
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    int indegree[n];
    memset(indegree, 0, sizeof(indegree));
    
    printf("Enter the pairs (horse_a horse_b):\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (!adj[a][b]) {
            adj[a][b] = 1;
            indegree[b]++;
        }
    }
    
    int result[n];
    topological_sort(n, adj, indegree, result);
    
    qsort(result, n, sizeof(int), compare);
    
    printf("The lexicographically smallest order of horses is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}
