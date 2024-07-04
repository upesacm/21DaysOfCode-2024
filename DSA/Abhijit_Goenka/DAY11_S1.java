
import java.util.LinkedList;
import java.util.Queue;
class DAY11_S1 
{
    
    public static final int[] dRow = {-1, 1, 0, 0}; 
    public static final int[] dCol = {0, 0, -1, 1}; 
    public static int minMoves(char[][] grid, int[] start, int[] goal) 
    {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();  
        queue.offer(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!queue.isEmpty()) 
        {
            int[] current = queue.poll();
            int row = current[0];
            int col = current[1];
            int dist = current[2];

            if (row == goal[0] && col == goal[1]) 
            {
                return dist;
            }

            for (int i = 0; i < 4; i++) 
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] == '.' && !visited[newRow][newCol]) 
                {
                    queue.offer(new int[]{newRow, newCol, dist + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return -1; 
    }

    public static boolean isValid(int row, int col, int rows, int cols) 
    {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
    public static void main(String[] args) 
    {
        char[][] grid = {
            {'.', '.', '.'},
            {'.', 'X', '.'},
            {'.', '.', '.'}
        };
        int[] start = {0, 0};
        int[] goal = {2, 2};

        int result = minMoves(grid, start, goal);
        System.out.println(result);
    }
}
