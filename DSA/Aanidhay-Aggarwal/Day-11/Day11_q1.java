import java.util.*;

public class Main {
    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        
        queue.add(start);
        visited[start[0]][start[1]] = true;
        int moves = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                if (curr[0] == goal[0] && curr[1] == goal[1]) {
                    return moves;
                }
                for (int[] dir : directions) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y]!= 'X' &&!visited[x][y]) {
                        queue.add(new int[]{x, y});
                        visited[x][y] = true;
                    }
                }
            }
            moves++;
        }
        return -1; // return -1 if goal is not reachable
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
