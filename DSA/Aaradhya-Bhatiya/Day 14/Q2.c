#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

int in[MAXN], adj[MAXN][MAXN], n, m;

void topoSort(int res[]) {
    int idx = 0;
    int queue[MAXN], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int minIdx = front;
        for (int i = front + 1; i < rear; i++) {
            if (queue[i] < queue[minIdx]) {
                minIdx = i;
            }
        }

        int u = queue[minIdx];
        queue[minIdx] = queue[front];
        front++;

        res[idx++] = u;

        for (int i = 0; i < n; i++) {
            if (adj[u][i]) {
                in[i]--;
                if (in[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        in[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        in[b]++;
    }

    int res[MAXN];
    topoSort(res);

    for (int i = n-1; i >= 0; i--) {
        printf("%d ", res[i]);
    }

    return 0;
}
