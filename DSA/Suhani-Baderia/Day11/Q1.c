#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void enqueue(Node** front, Node** rear, int x, int y) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if (*rear == NULL) {
        *front = *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

Node* dequeue(Node** front, Node** rear) {
    Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    return temp;
}

int bfs(char grid[][MAX], int n, int m, int sx, int sy, int gx, int gy) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int visited[n][m];
    memset(visited, 0, sizeof(visited));
    Node* front = NULL;
    Node* rear = NULL;
    enqueue(&front, &rear, sx, sy);
    visited[sx][sy] = 1;
    int level = 0;
    while (front!= NULL) {
        int size = 0;
        Node* temp = front;
        while (temp!= NULL) {
            int x = temp->x;
            int y = temp->y;
            if (x == gx && y == gy) {
                return level;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]!= 'X' &&!visited[nx][ny]) {
                    enqueue(&front, &rear, nx, ny);
                    visited[nx][ny] = 1;
                    size++;
                }
            }
            temp = temp->next;
        }
        while (size--) {
            Node* node = dequeue(&front, &rear);
            free(node);
        }
        level++;
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char grid[n][MAX];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    int sx, sy, gx, gy;
    scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    int ans = bfs(grid, n, m, sx, sy, gx, gy);
    printf("%d\n", ans);
    return 0;
}
