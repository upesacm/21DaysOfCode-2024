#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 100005

int graph[MAXN];
int indegree[MAXN];
int queue[MAXN];
int front, rear;

void addEdge(int u, int v) {
    graph[u] = v;
    indegree[v]++;
}

void topologicalSort(int n) {
    front = rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        if (graph[u] != -1) {
            indegree[graph[u]]--;
            if (indegree[graph[u]] == 0) {
                queue[rear++] = graph[u];
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        graph[i] = -1;
        indegree[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    topologicalSort(n);
    return 0;
}
