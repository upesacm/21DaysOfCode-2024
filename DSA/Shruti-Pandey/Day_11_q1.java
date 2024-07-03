import java.util.*;

class Solution {
    private static final int[][] DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start[0], start[1], 0}); 
        
        Set<String> visited = new HashSet<>();
        visited.add(start[0] + "," + start[1]);
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0];
            int col = current[1];
            int moves = current[2];
            
            if (row == goal[0] && col == goal[1]) {
                return moves;
            }
            
            
            for (int[] dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] != '#') {
                    String key = newRow + "," + newCol;
                    if (!visited.contains(key)) {
                        queue.offer(new int[]{newRow, newCol, moves + 1});
                        visited.add(key);
                    }
                }
            }
        }
        
        return -1;
    }
    
    private boolean isValid(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'x', '.'},
            {'.', '.', '.'}
        };
        int[] start = {0, 0};
        int[] goal = {2, 2};
        
        int result = solution.minMoves(grid, start, goal);
        System.out.println("Minimum number of moves: " + result);
    }
}
