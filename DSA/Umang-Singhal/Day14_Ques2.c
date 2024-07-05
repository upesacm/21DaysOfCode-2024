#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adjacencyMatrix[n][n];
    int inDegree[n];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjacencyMatrix[i][j] = 0;
        }
        inDegree[i] = 0;
    }
    for (i = 0; i < m; i++) {
        int horse_a, horse_b;
        scanf("%d %d", &horse_a, &horse_b);
        if (adjacencyMatrix[horse_a][horse_b] == 0) {
            adjacencyMatrix[horse_a][horse_b] = 1;
            inDegree[horse_b]++;
        }
    }
    int result[n];
    int queue[n];
    int front = 0, rear = 0;
    for (i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int resultIndex = 0;
    while (front < rear) {
        int minIndex = front;
        for (i = front + 1; i < rear; i++) {
            if (queue[i] < queue[minIndex]) {
                minIndex = i;
            }
        }
        int currentHorse = queue[minIndex];
        queue[minIndex] = queue[front];
        front++;
        result[resultIndex++] = currentHorse;
        for (i = 0; i < n; i++) {
            if (adjacencyMatrix[currentHorse][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    for (i = resultIndex-1; i >= 0; --i) {
        printf("%d ", result[i]);
    }
    return 0;
}
