#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int minMoves(vector<vector<char>> &grid, pair<int, int> start, pair<int, int> goal)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int moves = current.second;

        if (x == goal.first && y == goal.second)
        {
            return moves;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '.' && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                q.push({{newX, newY}, moves + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<char>> grid = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}};
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {2, 2};

    cout << minMoves(grid, start, goal) << endl;

    return 0;
}
