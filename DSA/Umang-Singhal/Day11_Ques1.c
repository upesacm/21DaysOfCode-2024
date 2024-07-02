#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
typedef struct {
    int x, y;
} Point;
int isValid(char grid[MAX][MAX], int visited[MAX][MAX], int x, int y, int rows, int cols) {
    return (x >= 0) && (x < rows) && (y >= 0) && (y < cols) && (grid[x][y] == '.') && !visited[x][y];
}
int bfs(char grid[MAX][MAX], int rows, int cols, Point start, Point goal) {
    int visited[MAX][MAX] = {0};
    Point queue[MAX * MAX];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.x][start.y] = 1;
    int moves = 0;
    while (front < rear) {
        int size = rear - front;
        while (size--) {
            Point current = queue[front++];
            if (current.x == goal.x && current.y == goal.y) {
                return moves;
            }
            for (int i = 0; i < 4; i++) {
                int newX = current.x + direction[i][0];
                int newY = current.y + direction[i][1];
                if (isValid(grid, visited, newX, newY, rows, cols)) {
                    queue[rear++] = (Point){newX, newY};
                    visited[newX][newY] = 1;
                }
            }
        }
        moves++;
    }
    return -1;
}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    char grid[MAX][MAX];
    printf("Enter the grid configuration (use '.' for unblocked and 'X' for blocked cells):\n");
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }
    Point start, goal;
    printf("Enter the start position (row and column): ");
    scanf("%d %d", &start.x, &start.y);
    printf("Enter the goal position (row and column): ");
    scanf("%d %d", &goal.x, &goal.y);
    int result = bfs(grid, rows, cols, start, goal);
    if (result != -1) {
        printf("The minimum number of moves is: %d\n", result);
    } else {
        printf("The goal is not reachable.\n");
    }
    return 0;
}
