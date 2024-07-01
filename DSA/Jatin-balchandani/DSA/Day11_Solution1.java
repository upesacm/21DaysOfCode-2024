import java.util.LinkedList;
import java.util.Queue;

public class Day11_Solution1 {
    // Directions array representing 4 possible movements (right, down, left, up)
    private static final int[][] DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{start[0], start[1], 0}); // {row, col, distance}
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0];
            int col = current[1];
            int distance = current[2];

            // If we've reached the goal, return the distance
            if (row == goal[0] && col == goal[1]) {
                return distance;
            }

            // Explore the 4 possible directions
            for (int[] direction : DIRECTIONS) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                // Check if the new position is within bounds and not visited
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol] && grid[newRow][newCol] == '.') {
                    visited[newRow][newCol] = true;
                    queue.add(new int[]{newRow, newCol, distance + 1});
                }
            }
        }

        // If the goal is not reachable, return -1
        return -1;
    }

    public static void main(String[] args) {
        Day11_Solution1 solution = new Day11_Solution1();
        char[][] grid = {
                {'.', '.', '.'},
                {'.', 'X', '.'},
                {'.', '.', '.'}
        };
        int[] start = {0, 0};
        int[] goal = {2, 2};

        int result = solution.minMoves(grid, start, goal);
        System.out.println("Minimum number of moves: " + result); // Output: 4
    }
}
