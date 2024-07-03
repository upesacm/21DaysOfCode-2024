// Question-1
// Author - Ayush Dey

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows in the grid: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns in the grid: ");
        int cols = scanner.nextInt();

        char[][] grid = new char[rows][cols];
        System.out.println("Enter the grid configuration ( '.' or 'X' ): ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = scanner.next().charAt(0);
            }
        }

        System.out.print("Enter the start position (e.g. (0, 0)): ");
        String[] startStr = scanner.next().replace("(", "").replace(")", "").split(",");
        int[] start = {Integer.parseInt(startStr[0].trim()), Integer.parseInt(startStr[1].trim())};

        System.out.print("Enter the goal position (e.g. (2, 2)): ");
        String[] goalStr = scanner.next().replace("(", "").replace(")", "").split(",");
        int[] goal = {Integer.parseInt(goalStr[0].trim()), Integer.parseInt(goalStr[1].trim())};

        int minMoves = minMoves(grid, start, goal);
        System.out.println("Minimum number of moves: " + minMoves);
    }

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
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] != 'X' && !visited[x][y]) {
                        queue.add(new int[]{x, y});
                        visited[x][y] = true;
                    }
                }
            }
            moves++;
        }

        return -1; // return -1 if goal is NOT REACHABLE
    }
}