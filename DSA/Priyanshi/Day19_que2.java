import java.util.*;

public class Day19_que2 {
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

        List<Integer> result = dfs(graph, startNode);

        for (int node : result) {
            System.out.print(node + " ");
        }
    }

    public static List<Integer> dfs(List<List<Integer>> graph, int startNode) {
        List<Integer> result = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();

        dfsHelper(graph, startNode, visited, result);

        return result;
    }

    public static void dfsHelper(List<List<Integer>> graph, int node, Set<Integer> visited, List<Integer> result) {
        visited.add(node);
        result.add(node);

        for (int neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                dfsHelper(graph, neighbor, visited, result);
            }
        }
    }
}
