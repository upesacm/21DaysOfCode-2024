import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<List<Integer>> tree = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            tree.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            tree.get(u).add(v);
            tree.get(v).add(u);
        }

        int[] A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextInt();
        }

        long totalDistance = 0;

        // Compute distances
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (A[i] == A[j]) {
                    totalDistance += bfs(tree, i, j, N);
                }
            }
        }

        System.out.println(totalDistance);
        
        scanner.close();
    }
    private static int bfs(List<List<Integer>> tree, int start, int target, int N) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N + 1];
        int[] distance = new int[N + 1];

        queue.add(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : tree.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    queue.add(neighbor);
                    if (neighbor == target) {
                        return distance[neighbor];
                    }
                }
            }
        }

        return 0;
    }
}
