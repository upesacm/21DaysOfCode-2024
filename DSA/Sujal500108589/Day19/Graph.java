import java.util.*;

public class Graph {
    private int nodes;
    private LinkedList<Integer>[] adjacencyList;

    // Constructor
    public Graph(int nodes) {
        this.nodes = nodes;
        adjacencyList = new LinkedList[nodes + 1];
        for (int i = 0; i <= nodes; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    public void addEdge(int u, int v) {
        adjacencyList[u].add(v);
        adjacencyList[v].add(u);
    }

    // BFS function to find shortest reach from a starting node
    public int[] bfsShortestReach(int start) {
        int[] distances = new int[nodes + 1];
        Arrays.fill(distances, -1); // Initialize distances to -1
        distances[start] = 0; // Distance to the starting node is 0

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            for (int neighbor : adjacencyList[currentNode]) {
                if (distances[neighbor] == -1) { // If the neighbor hasn't been visited
                    distances[neighbor] = distances[currentNode] + 1;
                    queue.add(neighbor);
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        // Example usage
        int n = 5; // Number of nodes
        Graph graph = new Graph(n);

        int[][] edges = {
            {1, 2},
            {1, 3},
            {3, 4}
        };

        for (int[] edge : edges) {
            graph.addEdge(edge[0], edge[1]);
        }

        int startNode = 1;
        int[] shortestReach = graph.bfsShortestReach(startNode);

        // Output the shortest reach to each node
        for (int i = 1; i <= n; i++) {
            System.out.println("Node " + i + ": " + shortestReach[i]);
        }
    }
}
