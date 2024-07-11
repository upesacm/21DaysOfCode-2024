#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//QUESTION1
#define MAX 100
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point point;
    int dist;
} QueueNode;
typedef struct {
    QueueNode arr[MAX * MAX];
    int front, rear;
} Queue;
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}
void enqueue(Queue *q, QueueNode node) {
    q->arr[q->rear++] = node;
}
QueueNode dequeue(Queue *q) {
    return q->arr[q->front++];
}
bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}
int minMoves(char grid[MAX][MAX], int rows, int cols, Point start, Point goal) {
    if (grid[start.x][start.y] == 'X' || grid[goal.x][goal.y] == 'X') {
        return -1;
    }

    bool visited[MAX][MAX] = {false};

    visited[start.x][start.y] = true;

    Queue q;
    initQueue(&q);
    QueueNode startNode = {start, 0};
    enqueue(&q, startNode);

    while (!isEmpty(&q)) {
        QueueNode current = dequeue(&q);
        Point pt = current.point;

        if (pt.x == goal.x && pt.y == goal.y) {
            return current.dist;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = pt.x + rowDir[i];
            int newCol = pt.y + colDir[i];

            if (isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                QueueNode adjNode = {{newRow, newCol}, current.dist + 1};
                enqueue(&q, adjNode);
            }
        }
    }
    return -1;
}

int main() {
    int rows = 3, cols = 3;
    char grid[MAX][MAX] = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };
    Point start = {0, 0};
    Point goal = {2, 2};

    int result = minMoves(grid, rows, cols, start, goal);

    if (result != -1) {
        printf("The minimum number of moves is %d\n", result);
    } else {
        printf("No path exists from start to goal\n");
    }

    return 0;
}
