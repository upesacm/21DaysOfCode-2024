#include <iostream>
#include <queue>
#include <vector>

using namespace std;

 vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 bool is_valid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

 int min_moves_to_goal(vector<vector<char>>& grid, pair<int, int>& start, pair<int, int>& goal) {
    if (start == goal) return 0; // If start is the same as goal, no moves needed
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    queue<pair<int, int>> q; // Queue for BFS with pairs (row, col)
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    q.push(start);
    visited[start.first][start.second] = true;
    int distance = 0;
    
    while (!q.empty()) {
        int q_size = q.size();
        
        for (int i = 0; i < q_size; ++i) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
             for (auto& dir : directions) {
                int new_row = row + dir.first;
                int new_col = col + dir.second;
                
                if (is_valid(new_row, new_col, rows, cols) && !visited[new_row][new_col] && grid[new_row][new_col] == '.') {
                    if (make_pair(new_row, new_col) == goal) {
                        return distance + 1; // Found the goal
                    }
                    
                    q.push(make_pair(new_row, new_col));
                    visited[new_row][new_col] = true;
                }
            }
        }
        
        distance++; // Increment distance after processing all nodes at the current level
    }
    
    return -1; // Goal is unreachable
}

int main() {
     vector<vector<char>> grid = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {2, 2};

    int min_moves = min_moves_to_goal(grid, start, goal);
    cout << "Minimum number of moves: " << min_moves << endl; // Output: 4

    return 0;
}
