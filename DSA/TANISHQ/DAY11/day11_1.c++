#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
    int x, y, moves;
};

int minMoves(vector<vector<int>>& grid, int startX, int startY, int goalX, int goalY) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Cell> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell cell = q.front();
        q.pop();

        if (cell.x == goalX && cell.y == goalY) {
            return cell.moves;
        }

        for (int i = 0; i < 4; i++) {
            int newX = cell.x + dx[i];
            int newY = cell.y + dy[i];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY] && grid[newX][newY] == 0) {
                q.push({newX, newY, cell.moves + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1; // no path found
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };
    int startX = 0, startY = 0, goalX = 3, goalY = 3;

    int minMoves = minMoves(grid, startX, startY, goalX, goalY);
    cout << "Minimum moves: " << minMoves << endl;

    return 0;
}