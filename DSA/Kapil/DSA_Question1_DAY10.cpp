#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
  return 0 <= row && row < rows && 0 <= col && col < cols && grid[row][col] == '.';
}

int minMoves(vector<vector<char>>& grid, pair<int, int>& start, pair<int, int>& goal) {
  int rows = grid.size();
  int cols = grid[0].size();

  // Directions for moving up, right, down, and left
  vector<int> dr = {0, 1, 0, -1};
  vector<int> dc = {1, 0, -1, 0};

  // Simple recursive DFS implementation
  function<int(int, int, int)> dfs = [&](int row, int col, int moves) {
    if (row == goal.first && col == goal.second) {
      return moves;
    }

    for (int i = 0; i < 4; ++i) {
      int newRow = row + dr[i];
      int newCol = col + dc[i];
      if (isValid(grid, newRow, newCol, rows, cols)) {
        grid[row][col] = 'X'; 
        int result = dfs(newRow, newCol, moves + 1);
        if (result != -1) {
          return result;
        }
        grid[row][col] = '.'; 
      }
    }

    return -1; 
  };

  int result = dfs(start.first, start.second, 0);
  return result;
}

int main() {
  vector<vector<char>> grid = {
    {'.', '.', '.'},
    {'.', 'X', '.'},
    {'.', '.', '.'}
  };
  pair<int, int> start = {0, 0};
  pair<int, int> goal = {2, 2};

  int min_moves = minMoves(grid, start, goal);

  if (min_moves != -1) {
    cout << "Minimum number of moves required: " << min_moves << endl;
  } else {
    cout << "No path exists from start to goal." << endl;
  }

  return 0;
}
