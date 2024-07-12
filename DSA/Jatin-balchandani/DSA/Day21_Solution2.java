import java.util.*;

public class Day21_Solution2 {

    static class Node {
        int index;
        List<Integer> neighbors;

        Node(int index) {
            this.index = index;
            this.neighbors = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Read tree edges
        List<Node> tree = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            tree.add(new Node(i));
        }

        for (int i = 0; i < N - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            tree.get(u).neighbors.add(v);
            tree.get(v).neighbors.add(u);
        }

        // Read sequence A
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Calculate distances using BFS
        int[][] dist = new int[N][N];

        // BFS function
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N + 1];
        int[] distance = new int[N + 1];

        for (int start = 1; start <= N; start++) {
            queue.clear();
            Arrays.fill(visited, false);
            Arrays.fill(distance, 0);

            queue.add(start);
            visited[start] = true;

            while (!queue.isEmpty()) {
                int current = queue.poll();

                for (int neighbor : tree.get(current).neighbors) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        distance[neighbor] = distance[current] + 1;
                        queue.add(neighbor);

                        // Record distance
                        dist[start - 1][neighbor - 1] = distance[neighbor];
                    }
                }
            }
        }

        // Calculate the result
        long result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (A[i] == A[j]) {
                    result += dist[i][j];
                }
            }
        }

        System.out.println(result);
    }
}
