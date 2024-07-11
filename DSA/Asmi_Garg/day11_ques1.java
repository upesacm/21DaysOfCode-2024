import java.util.*;

public class Main {
    static int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public static int minMoves(char[][] grid, int[] start, int[] goal) {
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(start);
        visited.add(start[0] + "," + start[1]);
        int moves = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] pos = queue.poll();
                if (pos[0] == goal[0] && pos[1] == goal[1]) {
                    return moves;
                }
                for (int[] dir : directions) {
                    int x = pos[0] + dir[0];
                    int y = pos[1] + dir[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != 'X' && !visited.contains(x + "," + y)) {
                        queue.add(new int[]{x, y});
                        visited.add(x + "," + y);
                    }
                }
            }
            moves++;
        }

        return -1;  // return -1 if goal is not reachable
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
