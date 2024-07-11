import java.util.*;

public class Day19_que1 {
    public static void main(String[] args) {
        // Example graph
        int numNodes = 6;
        int numEdges = 7;
        int[][] edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}, {5, 6}};
        int startNode = 1;

        // Create an adjacency list to represent the graph
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= numNodes; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        // Perform BFS
        int[] distances = bfs(graph, startNode);

        // Print the shortest reach to each node
        for (int i = 1; i <= numNodes; i++) {
            System.out.print("Node " + i + ": " + distances[i] + " ");
        }
    }

    public static int[] bfs(List<List<Integer>> graph, int startNode) {
        int numNodes = graph.size() - 1;
        int[] distances = new int[numNodes + 1];
        Arrays.fill(distances, -1);
        distances[startNode] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(startNode);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[node] + 1;
                    queue.add(neighbor);
                }
            }
        }

        return distances;
    }
}
