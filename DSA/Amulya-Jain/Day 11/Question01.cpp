#include <iostream>
#include <queue>
#include <cstring> // for memset

using namespace std;

const int MAX = 100; // Assuming maximum grid size
char grid[MAX][MAX];
int visited[MAX][MAX];
int rows, cols;

struct Point {
    int x, y;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(Point start, Point goal) {
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = 1;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == goal.x && curr.y == goal.y) {
            return visited[curr.x][curr.y] - 1;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                grid[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = visited[curr.x][curr.y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    return -1; 
}

int main() 
{
    rows = 3;
    cols = 3;
    Point start = { 0, 0 };
    Point goal = { 2, 2 };

    memset(visited, 0, sizeof(visited));

    char grid[MAX][MAX] = {
        { '.', '.', '.' },
        { '.', 'X', '.' },
        { '.', '.', '.' }
    };

    int minMoves = bfs(start, goal);
    cout << "Minimum number of moves: " << minMoves << endl;

    return 0;
}
