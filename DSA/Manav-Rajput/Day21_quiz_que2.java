package new3;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class TreePaths {

    // Class to store a node and its distance from the source
    static class NodeDistance {
        int node;
        int distance;

        NodeDistance(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }

    // Function to calculate the shortest paths in the tree
    public static int calculatePaths(int N, int[][] edges, int[] A) {
        // Create an adjacency list for the tree
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            tree.add(new ArrayList<>());
        }

        // Populate the adjacency list with the edges
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        int totalDistance = 0;

        // Calculate distances using BFS
        for (int i = 1; i <= N; i++) {
            if (A[i - 1] != 0) {
                boolean[] visited = new boolean[N + 1];
                Queue<NodeDistance> queue = new LinkedList<>();
                queue.add(new NodeDistance(i, 0));
                visited[i] = true;

                while (!queue.isEmpty()) {
                    NodeDistance current = queue.poll();
                    for (int neighbor : tree.get(current.node)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            queue.add(new NodeDistance(neighbor, current.distance + 1));
                            if (A[neighbor - 1] == A[i - 1]) {
                                totalDistance += current.distance + 1;
                            }
                        }
                    }
                }
            }
        }

        return totalDistance / 2; // Each distance is counted twice, so divide by 2
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices
        int N = scanner.nextInt();

        // Read the edges
        int[][] edges = new int[N - 1][2];
        for (int i = 0; i < N - 1; i++) {
            edges[i][0] = scanner.nextInt();
            edges[i][1] = scanner.nextInt();
        }

        // Read the sequence A
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Calculate the total distance
        int result = calculatePaths(N, edges, A);
        System.out.println(result);

        scanner.close();
    }
}
