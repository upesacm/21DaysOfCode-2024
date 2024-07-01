import java.util.*;

class GridPathfinder {
    static class Point {
        int x, y, moves;
        Point(int x, int y, int moves) {
            this.x = x;
            this.y = y;
            this.moves = moves;
        }
    }

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(start[0], start[1], 0));
        visited[start[0]][start[1]] = true;
        
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.isEmpty()) {
            Point point = queue.poll();
            
            if (point.x == goal[0] && point.y == goal[1]) {
                return point.moves;
            }
            
            for (int[] dir : directions) {
                int nx = point.x + dir[0];
                int ny = point.y + dir[1];
                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    queue.add(new Point(nx, ny, point.moves + 1));
                }
            }
        }
        
        return -1; // If the goal is not reachable
    }

    public static void main(String[] args) {
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'X', '.'},
            {'.', '.', '.'}
        };
        int[] start = {0, 0};
        int[] goal = {2, 2};
        
        System.out.println(minMoves(grid, start, goal)); // Output: 4
    }
}
