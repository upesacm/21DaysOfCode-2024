#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 

typedef struct {
    int x, y, moves;
} QueueNode;

typedef struct {
    QueueNode *nodes;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->nodes = (QueueNode*)malloc(capacity * sizeof(QueueNode));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue *q, int x, int y, int moves) {
    if (q->rear < q->capacity) {
        q->nodes[q->rear].x = x;
        q->nodes[q->rear].y = y;
        q->nodes[q->rear].moves = moves;
        q->rear++;
    }
}

QueueNode dequeue(Queue *q) {
    QueueNode node = q->nodes[q->front];
    q->front++;
    return node;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

int isValidMove(int x, int y, int rows, int cols, char grid[rows][cols], int visited[rows][cols]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '.' && !visited[x][y]);
}

int minMoves(int rows, int cols, char grid[rows][cols], int startX, int startY, int goalX, int goalY) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int visited[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = 0;

    Queue *q = createQueue(rows * cols);
    enqueue(q, startX, startY, 0);
    visited[startX][startY] = 1;

    while (!isQueueEmpty(q)) {
        QueueNode node = dequeue(q);
        if (node.x == goalX && node.y == goalY) {
            free(q->nodes);
            free(q);
            return node.moves;
        }

        for (int i = 0; i < 4; i++) {
            int newX = node.x + directions[i][0];
            int newY = node.y + directions[i][1];
            if (isValidMove(newX, newY, rows, cols, grid, visited)) {
                enqueue(q, newX, newY, node.moves + 1);
                visited[newX][newY] = 1;
            }
        }
    }
    free(q->nodes);
    free(q);
    return -1;  
}

int main() {

    char grid[3][3] = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };

    int startX = 0, startY = 0;
    int goalX = 2, goalY = 2;

    int result = minMoves(3, 3, grid, startX, startY, goalX, goalY);
    if (result != -1)
        printf("Minimum moves: %d\n", result);
    else
        printf("Goal is not reachable.\n");

    return 0;
}
