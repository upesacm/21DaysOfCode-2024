import java.util.LinkedList;
import java.util.Queue;
class Point {
    int x, y, distance;
    Point(int x, int y, int distance) {
        this.x = x;
        this.y = y;
        this.distance = distance;
    }
}
public class Day11_ques1 {
    private static final int[] rowDirection = {-1, 1, 0, 0};
    private static final int[] colDirection = {0, 0, -1, 1};
    public static int minMoves(char[][] grid, Point start, Point goal) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        Queue<Point> queue = new LinkedList<>();

        queue.add(new Point(start.x, start.y, 0));
        visited[start.x][start.y] = true;

        while (!queue.isEmpty()) {
            Point current = queue.poll();

            if (current.x == goal.x && current.y == goal.y) {
                return current.distance;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = current.x + rowDirection[i];
                int newCol = current.y + colDirection[i];

                if (isValidMove(newRow, newCol, rows, cols, grid, visited)) {
                    queue.add(new Point(newRow, newCol, current.distance + 1));
                    visited[newRow][newCol] = true;
                }
            }
        }
        return -1;
    }

    private static boolean isValidMove(int row, int col, int rows, int cols, char[][] grid, boolean[][] visited) {
        return row >= 0 && row < rows && col >= 0 && col < cols 
               && grid[row][col] == '.' && !visited[row][col];
    }
    public static void main(String[] args) {
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'X', '.'},
            {'.', '.', '.'}
        };
        Point start = new Point(0, 0, 0);
        Point goal = new Point(2, 2, 0);
        int result = minMoves(grid, start, goal);
        System.out.println("Minimum number of moves: " + result);
    }
}
