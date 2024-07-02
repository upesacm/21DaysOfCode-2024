
import java.util.LinkedList;
import java.util.Queue;

class Main {
    static class Cell {
        int row, col, dist;
        
        Cell(int row, int col, int dist) {
            this.row = row;
            this.col = col;
            this.dist = dist;
        }
    }

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        
        // Directions for moving up, down, left, right
        int[] rowDirection = {-1, 1, 0, 0};
        int[] colDirection = {0, 0, -1, 1};

        Queue<Cell> queue = new LinkedList<>();
        queue.add(new Cell(start[0], start[1], 0));
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            Cell current = queue.poll();

            // If we reached the goal
            if (current.row == goal[0] && current.col == goal[1]) {
                return current.dist;
            }

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = current.row + rowDirection[i];
                int newCol = current.col + colDirection[i];

                // Check if the new position is within bounds and not visited or blocked
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    !visited[newRow][newCol] && grid[newRow][newCol] == '.') {
                    queue.add(new Cell(newRow, newCol, current.dist + 1));
                    visited[newRow][newCol] = true;
                }
            }
        }

        // If we can't reach the goal
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

        int result = minMoves(grid, start, goal);
        System.out.println("Minimum moves required: " + result);
    }
}
