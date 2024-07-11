#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y, int rows, int cols, vector<vector<char>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '.';
}

int minMoves(vector<vector<char>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = 'X';
    int moves = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front(); q.pop();
            if (x == goal.first && y == goal.second) {
                return moves;
            }

            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (isValid(newX, newY, rows, cols, grid)) {
                    q.push({newX, newY});
                    grid[newX][newY] = 'X';
                }
            }
        }
        ++moves;
    }

    return -1; // Goal not reachable
}

int main() {
    vector<vector<char>> grid = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {2, 2};

    int result = minMoves(grid, start, goal);

    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "No path found from start to goal." << endl;
    }

    return 0;
}
