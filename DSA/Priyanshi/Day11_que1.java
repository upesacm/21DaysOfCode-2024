import java.util.*;

public class Day11_que1 {

    private static final int[] ROW_DIRECTIONS = {-1, 1, 0, 0};
    private static final int[] COL_DIRECTIONS = {0, 0, -1, 1};

    //to check if a cell is within the grid and is unblocked
    private static boolean isValidMove(char[][] grid, boolean[][] visited, int row, int col) {
        return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length 
                && grid[row][col] == '.' && !visited[row][col];
    }

    // to find the minimum number of moves using BFS
    public static int findMinimumMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentRow = current[0];
            int currentCol = current[1];
            int currentDistance = current[2];

            // Check if we have reached the goal
            if (currentRow == goal[0] && currentCol == goal[1]) {
                return currentDistance;
            }

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + ROW_DIRECTIONS[i];
                int newCol = currentCol + COL_DIRECTIONS[i];

                if (isValidMove(grid, visited, newRow, newCol)) {
                    queue.offer(new int[]{newRow, newCol, currentDistance + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }

        // Return -1 if there is no valid path
        return -1;
    }

    public static void main(String[] args) {
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'X', '.'},
            {'.', '.', '.'}
        };
        int[] start = {0, 0};
        int[] goal = {2, 2};

        int result = findMinimumMoves(grid, start, goal);
        System.out.println("Minimum moves required: " + result);
    }
}
