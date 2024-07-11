import java.util.*;

public class GraphShortestReach {
    public static int[] bfsShortestReach(int numNodes, int[][] edges, int startNode) {
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

        // Initialize distances
        int[] distances = new int[numNodes + 1];
        Arrays.fill(distances, -1);
        distances[startNode] = 0;

        // BFS initialization
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startNode);

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            int currentDistance = distances[currentNode];

            for (int neighbor : graph.get(currentNode)) {
                if (distances[neighbor] == -1) { // If neighbor hasn't been visited
                    distances[neighbor] = currentDistance + 1;
                    queue.add(neighbor);
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        int numNodes = 6;
        int[][] edges = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 6}};
        int startNode = 1;

        int[] result = bfsShortestReach(numNodes, edges, startNode);
        for (int i = 1; i <= numNodes; i++) {
            System.out.println("Node " + i + ": " + result[i]);
        }
    }
}
