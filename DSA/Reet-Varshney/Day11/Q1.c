#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct QueueNode {
    int row, col;
    struct QueueNode* next;
} QueueNode;

void addToQueue(QueueNode** queueFront, QueueNode** queueRear, int row, int col) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    if (*queueRear == NULL) {
        *queueFront = *queueRear = newNode;
    } else {
        (*queueRear)->next = newNode;
        *queueRear = newNode;
    }
}

QueueNode* removeFromQueue(QueueNode** queueFront, QueueNode** queueRear) {
    QueueNode* tempNode = *queueFront;
    *queueFront = (*queueFront)->next;
    if (*queueFront == NULL) {
        *queueRear = NULL;
    }
    return tempNode;
}

int performBFS(char grid[][MAX_SIZE], int rows, int cols, int startX, int startY, int goalX, int goalY) {
    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    int visited[rows][cols];
    memset(visited, 0, sizeof(visited));
    QueueNode* queueFront = NULL;
    QueueNode* queueRear = NULL;
    addToQueue(&queueFront, &queueRear, startX, startY);
    visited[startX][startY] = 1;
    int distance = 0;
    while (queueFront != NULL) {
        int nodesInCurrentLevel = 0;
        QueueNode* tempNode = queueFront;
        while (tempNode != NULL) {
            int x = tempNode->row;
            int y = tempNode->col;
            if (x == goalX && y == goalY) {
                return distance;
            }
            for (int i = 0; i < 4; i++) {
                int newX = x + dRow[i];
                int newY = y + dCol[i];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != 'X' && !visited[newX][newY]) {
                    addToQueue(&queueFront, &queueRear, newX, newY);
                    visited[newX][newY] = 1;
                    nodesInCurrentLevel++;
                }
            }
            tempNode = tempNode->next;
        }
        while (nodesInCurrentLevel--) {
            QueueNode* nodeToRemove = removeFromQueue(&queueFront, &queueRear);
            free(nodeToRemove);
        }
        distance++;
    }
    return -1;
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    char grid[rows][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }
    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);
    int result = performBFS(grid, rows, cols, startX, startY, goalX, goalY);
    printf("Shortest path length: %d\n", result);
    return 0;
}
