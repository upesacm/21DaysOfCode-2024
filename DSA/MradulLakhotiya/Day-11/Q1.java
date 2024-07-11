import java.util.LinkedList;
import java.util.Queue;

public class Q1 {

    public static int solution(char[][] grid, int[] start, int[] goal) {
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        Queue<int[]> BFS = new LinkedList<>();
        BFS.add(start);

        boolean[][] visited = new boolean[grid.length][grid[0].length];
        visited[start[0]][start[1]] = true;

        int moves = 0;

        while(!BFS.isEmpty()) {
            int level_size = BFS.size();
            
            for (int i = 0; i < level_size; i++) {
                int[] current = BFS.poll();
                
                if (current[0] == goal[0] && current[1] == goal[1]) {
                    return moves;
                }

                for (int[] direction : directions) {
                    int new_row = direction[0] + current[0];
                    int new_col = direction[1] + current[1];

                    if (new_row >= 0 && new_row < grid.length &&
                        new_col >= 0 && new_col < grid[0].length &&
                        grid[new_row][new_col] == '.' &&
                        !visited[new_row][new_col]) {

                        visited[new_row][new_col] = true;
                        BFS.add(new int[]{new_row, new_col});
                    }
                }
            }

            moves++;
        }

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
        
        System.out.println(solution(grid, start, goal));
    }
}