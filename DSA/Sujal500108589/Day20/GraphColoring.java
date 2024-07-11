import java.util.*;

public class GraphColoring {

    // Function to check if the graph is bipartite using BFS
    public static boolean isBipartite(int vertices, List<int[]> edges) {
        // Create an adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }

        // Populate the adjacency list
        for (int[] edge : edges) {
            graph.get(edge[0] - 1).add(edge[1] - 1);
            graph.get(edge[1] - 1).add(edge[0] - 1);
        }

        // Initialize color array, -1 means uncolored
        int[] color = new int[vertices];
        Arrays.fill(color, -1);

        // Check each component of the graph
        for (int i = 0; i < vertices; i++) {
            if (color[i] == -1) {
                // If the component hasn't been colored, perform BFS
                if (!bfsCheck(graph, color, i)) {
                    return false;
                }
            }
        }

        return true;
    }

    // Helper function to perform BFS and color the graph
    private static boolean bfsCheck(List<List<Integer>> graph, int[] color, int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        color[start] = 0; // Start coloring with 0

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (color[neighbor] == -1) {
                    // Color with opposite color
                    color[neighbor] = 1 - color[node];
                    queue.add(neighbor);
                } else if (color[neighbor] == color[node]) {
                    // If neighbor has the same color, it's not bipartite
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        int vertices = 4;
        List<int[]> edges = Arrays.asList(
            new int[]{1, 2},
            new int[]{1, 3},
            new int[]{2, 4},
            new int[]{3, 4}
        );

        if (isBipartite(vertices, edges)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
