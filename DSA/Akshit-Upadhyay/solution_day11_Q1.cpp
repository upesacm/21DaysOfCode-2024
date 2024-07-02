#include <iostream>
#include <queue>
#include <cstring> 
using namespace std;

#define ROWS 3
#define COLS 3

using namespace std;

#define ROWS 3
#define COLS 3

bool isValid(char grid[][COLS], int row, int col) {
  return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS) && grid[row][col] == '.';
}

int minMoves(char grid[][COLS], int startRow, int startCol, int goalRow, int goalCol) {

  queue<pair<int, int>> q;

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, -1, 0, 1};

  bool visited[ROWS][COLS];
  memset(visited, false, sizeof(visited));

  visited[startRow][startCol] = true;
  q.push({startRow, startCol});

  int level = 0;

  while (!q.empty()) {
    int size = q.size(); 
    for (int i = 0; i < size; i++) {
      pair<int, int> current = q.front();
      q.pop();

      if (current.first == goalRow && current.second == goalCol) {
        return level;
      }

      for (int j = 0; j < 4; j++) {
        int newRow = current.first + dx[j];
        int newCol = current.second + dy[j];

        if (isValid(grid, newRow, newCol) && !visited[newRow][newCol]) {
          visited[newRow][newCol] = true;
          q.push({newRow, newCol});
        }
      }
    }

    level++;
  }

  return -1;
}

int main() {
  char grid[ROWS][COLS] = {
    {'.', '.', '.'},
    {'.', 'X', '.'},
    {'.', '.', '.'}
  };

  int startRow = 0, startCol = 0;
  int goalRow = 2, goalCol = 2;

  int moves = minMoves(grid, startRow, startCol, goalRow, goalCol);

  if (moves == -1) {
    cout << "No path found." << endl;
  } else {
    cout << moves << endl;
  }

  return 0;
}
