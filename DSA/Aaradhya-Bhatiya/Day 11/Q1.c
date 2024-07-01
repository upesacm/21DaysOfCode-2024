#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define N 3
#define M 3

int directions[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

typedef struct {
    int x, y, dist;
} Node;

typedef struct {
    Node nodes[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

void enqueue(Queue *q, int x, int y, int dist) {
    q->nodes[q->rear].x = x;
    q->nodes[q->rear].y = y;
    q->nodes[q->rear].dist = dist;
    q->rear++;
}

Node dequeue(Queue *q) {
    return q->nodes[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isValid(int x, int y, char grid[N][M], int visited[N][M]) {
    return (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '.' && !visited[x][y]);
}

int minMoves(char grid[N][M], int startX, int startY, int goalX, int goalY) {
    Queue q;
    initQueue(&q);
    enqueue(&q, startX, startY, 0);

    int visited[N][M] = {0};
    visited[startX][startY] = 1;

    while (!isEmpty(&q)) {
        Node node = dequeue(&q);

        if (node.x == goalX && node.y == goalY)
            return node.dist;

        for (int i = 0; i < 4; i++) {
            int newX = node.x + directions[i][0];
            int newY = node.y + directions[i][1];

            if (isValid(newX, newY, grid, visited)) {
                enqueue(&q, newX, newY, node.dist + 1);
                visited[newX][newY] = 1;
            }
        }
    }
    return -1;
}

int main() {
    char grid[N][M] = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };
    int startX = 0, startY = 0;
    int goalX = 2, goalY = 2;

    int result = minMoves(grid, startX, startY, goalX, goalY);
    if (result != -1)
        printf("Minimum moves: %d\n", result);
    else
        printf("Path not found.\n");

    return 0;
}
