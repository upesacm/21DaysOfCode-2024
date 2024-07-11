import java.util.LinkedList;
import java.util.Queue;

public class MinMoves {

    // Helper class to store the position and move count
    static class Position {
        int row, col, moves;

        Position(int row, int col, int moves) {
            this.row = row;
            this.col = col;
            this.moves = moves;
        }
    }

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        // Directions for moving in the grid (up, down, left, right)
        int[][] directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        
        // Initialize the queue with the start position and move counter
        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(start[0], start[1], 0));
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        visited[start[0]][start[1]] = true;
        
        while (!queue.isEmpty()) {
            Position current = queue.poll();
            
            // If we have reached the goal, return the number of moves
            if (current.row == goal[0] && current.col == goal[1]) {
                return current.moves;
            }
            
            // Explore all possible moves
            for (int[] direction : directions) {
                int nextRow = current.row + direction[0];
                int nextCol = current.col + direction[1];
                
                // Check if the move is within the grid and not blocked
                if (nextRow >= 0 && nextRow < grid.length && nextCol >= 0 && nextCol < grid[0].length 
                    && grid[nextRow][nextCol] == '.' && !visited[nextRow][nextCol]) {
                    
                    // Mark the position as visited and add it to the queue
                    visited[nextRow][nextCol] = true;
                    queue.add(new Position(nextRow, nextCol, current.moves + 1));
                }
            }
        }
        
        // If the goal is not reachable, return -1 or some indication
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

        System.out.println(minMoves(grid, start, goal));  // Output: 4
    }
}
