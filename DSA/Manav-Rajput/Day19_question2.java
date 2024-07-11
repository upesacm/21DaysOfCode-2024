package new1;
import java.util.*;

public class DepthFirstSearch {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of nodes and edges
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();

        // Initialize the adjacency list for the graph (1-based indexing)
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= nodes; i++) {
            graph.add(new ArrayList<>());
        }

        // Read edges
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // Read starting node
        int startNode = scanner.nextInt();
        scanner.close();

        // Perform DFS and get the nodes visited
        List<Integer> visitedNodes = new ArrayList<>();
        boolean[] visited = new boolean[nodes + 1]; // 1-based indexing

        // Start DFS from the specified starting node
        dfs(graph, startNode, visited, visitedNodes);

        // Print nodes visited in DFS order
        System.out.println("Nodes visited in DFS order:");
        for (int node : visitedNodes) {
            System.out.print(node + " ");
        }
        System.out.println();
    }

    private static void dfs(List<List<Integer>> graph, int node, boolean[] visited, List<Integer> visitedNodes) {
        // Mark the current node as visited
        visited[node] = true;
        visitedNodes.add(node);

        // Visit all neighbors of the current node
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, visited, visitedNodes);
            }
        }
    }
}
