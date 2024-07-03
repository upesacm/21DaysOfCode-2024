#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<vector<char>> &grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> moves(rows, vector<int>(cols, INT_MAX));
    moves[start.first][start.second] = 0;
    
    queue<pair<int, int>> q;
    q.push(start);
    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        for (auto dir : directions) {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] != 'X') {
                if (moves[newRow][newCol] > moves[current.first][current.second] + 1) {
                    moves[newRow][newCol] = moves[current.first][current.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
    return moves[goal.first][goal.second] == INT_MAX ? -1 : moves[goal.first][goal.second];
}

int main() {
    vector<vector<char>> grid = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };
    pair<int, int> start(0, 0);
    pair<int, int> goal(2, 2);
    cout << minMoves(grid, start, goal) << endl;
    return 0;
}
