import java.util.LinkedList;
import java.util.Queue;

public class Day11_Q1 {
    private static final int[] ROW_DIRECTIONS = { -1, 1, 0, 0 };
    private static final int[] COL_DIRECTIONS = { 0, 0, -1, 1 };

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { start[0], start[1], 0 }); // {row, col, distance}
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentRow = current[0];
            int currentCol = current[1];
            int currentDist = current[2];

            if (currentRow == goal[0] && currentCol == goal[1]) {
                return currentDist;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + ROW_DIRECTIONS[i];
                int newCol = currentCol + COL_DIRECTIONS[i];

                if (isValidMove(newRow, newCol, grid, visited)) {
                    visited[newRow][newCol] = true;
                    queue.add(new int[] { newRow, newCol, currentDist + 1 });
                }
            }
        }
        return -1; // If no path is found
    }

    private static boolean isValidMove(int row, int col, char[][] grid, boolean[][] visited) {
        return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length
                && grid[row][col] == '.' && !visited[row][col];
    }

    public static void main(String[] args) {
        char[][] grid = {
                { '.', '.', '.' },
                { '.', 'X', '.' },
                { '.', '.', '.' }
        };
        int[] start = { 0, 0 };
        int[] goal = { 2, 2 };

        int result = minMoves(grid, start, goal);
        if (result != -1) {
            System.out.println("Minimum number of moves: " + result);
        } else {
            System.out.println("No path found");
        }
    }
}
