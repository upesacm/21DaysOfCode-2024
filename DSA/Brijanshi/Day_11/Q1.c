#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct Cell {
    int row;
    int col;
    int distance;
    struct Cell* next;
} Cell;

int isValidCell(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int isBlocked(char grid[][MAX_COLS], int row, int col) {
    return grid[row][col] == 'X';
}

int bfs(char grid[][MAX_COLS], int startRow, int startCol, int goalRow, int goalCol, int rows, int cols) {
    Cell* queue = (Cell*)malloc(sizeof(Cell) * rows * cols);
    int front = 0, rear = 0;

    Cell startCell = {startRow, startCol, 0, NULL};
    queue[rear++] = startCell;

    int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (front < rear) {
        Cell currentCell = queue[front++];
        int currentRow = currentCell.row;
        int currentCol = currentCell.col;
        int currentDistance = currentCell.distance;

        if (currentRow == goalRow && currentCol == goalCol) {
            return currentDistance;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];

            if (isValidCell(newRow, newCol, rows, cols) &&!isBlocked(grid, newRow, newCol)) {
                Cell newCell = {newRow, newCol, currentDistance + 1, NULL};
                queue[rear++] = newCell;
            }
        }
    }

    return -1; 
}

int main() {
    char grid[][MAX_COLS] = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };

    int rows = sizeof(grid) / sizeof(grid[0]);
    int cols = sizeof(grid[0]) / sizeof(grid[0][0]);

    int startRow = 0;
    int startCol = 0;
    int goalRow = 2;
    int goalCol = 2;

    int minMoves = bfs(grid, startRow, startCol, goalRow, goalCol, rows, cols);

    if (minMoves!= -1) {
        printf("Minimum number of moves: %d\n", minMoves);
    } else {
        printf("No path found\n");
    }

    return 0;
}
