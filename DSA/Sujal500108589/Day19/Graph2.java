import java.util.*;

public class Graph2 {
    private int nodes;
    private LinkedList<Integer>[] adjacencyList;

    // Constructor
    public Graph2(int nodes) {
        this.nodes = nodes;
        adjacencyList = new LinkedList[nodes + 1];
        for (int i = 0; i <= nodes; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    public void addEdge(int u, int v) {
        adjacencyList[u].add(v);
        adjacencyList[v].add(u); // Since the graph is undirected
    }

    // DFS function
    public List<Integer> dfs(int start) {
        List<Integer> visitedNodes = new ArrayList<>();
        boolean[] visited = new boolean[nodes + 1]; // Track visited nodes

        dfsUtil(start, visited, visitedNodes);

        return visitedNodes;
    }

    // Utility function for DFS
    private void dfsUtil(int node, boolean[] visited, List<Integer> visitedNodes) {
        visited[node] = true;
        visitedNodes.add(node);

        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, visitedNodes);
            }
        }
    }

    public static void main(String[] args) {
        // Example usage
        int n = 5; // Number of nodes
        Graph2 graph = new Graph2(n);

        int[][] edges = {
            {1, 2},
            {1, 3},
            {2, 4},
            {3, 5}
        };

        for (int[] edge : edges) {
            graph.addEdge(edge[0], edge[1]);
        }

        int startNode = 1;
        List<Integer> dfsOrder = graph.dfs(startNode);

        // Output the DFS order
        System.out.println("DFS Order: " + dfsOrder);
    }
}
