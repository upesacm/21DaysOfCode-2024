

import java.util.LinkedList;
import java.util.Queue;


public class Day11_01July_Ques1 {

    // Direcitons for moving up, down, left, and right
    private static final int[] rowDir = {-1, 1, 0, 0};
    private static final int[] colDir = {0, 0, -1, 1};

    public static void main(String[] args) {
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'X', '.'},
            {'.', '.', '.'}
        };

        int[] start = {0, 0};
        int[] goal = {2, 2};

        int moves = minMoves(grid, start, goal);
        System.out.println(moves); 
    }

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        
        // start position 
        queue.add(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentRow = current[0];
            int currentCol = current[1];
            int currentMoves = current[2];

            // Check for goal
            if (currentRow == goal[0] && currentCol == goal[1]) {
                return currentMoves;
            }

            // other  direcitons
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + rowDir[i];
                int newCol = currentCol + colDir[i];

                // valid position or not
                if (isValidMove(newRow, newCol, grid, visited)) {
                    queue.add(new int[]{newRow, newCol, currentMoves + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return -1;
    }

    private static boolean isValidMove(int row, int col, char[][] grid, boolean[][] visited) {
        return row >= 0 && row < grid.length &&
               col >= 0 && col < grid[0].length &&
               grid[row][col] != 'X' &&
               !visited[row][col];
    }
}
