import java.util.*;

public class GraphDFSRecursive {
    public static void dfs(int currentNode, boolean[] visited, List<List<Integer>> graph, List<Integer> result) {
        visited[currentNode] = true;
        result.add(currentNode);

        for (int neighbor : graph.get(currentNode)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, graph, result);
            }
        }
    }

    public static List<Integer> dfsTraversal(int numNodes, int[][] edges, int startNode) {
        // Create adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= numNodes; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // Initialize visited array and result list
        boolean[] visited = new boolean[numNodes + 1];
        List<Integer> result = new ArrayList<>();

        // Start DFS from the start node
        dfs(startNode, visited, graph, result);

        return result;
    }

    public static void main(String[] args) {
        int numNodes = 6;
        int[][] edges = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 6}};
        int startNode = 1;

        List<Integer> result = dfsTraversal(numNodes, edges, startNode);
        for (int node : result) {
            System.out.print(node + " ");
        }
    }
}
