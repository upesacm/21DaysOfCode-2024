import java.util.*;

public class DijkstraAlgorithm {

    public static int[] dijkstra(int vertices, List<int[]> edges, int start) {
        // Create an adjacency list
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }

        // Populate the adjacency list
        for (int[] edge : edges) {
            graph.get(edge[0] - 1).add(new int[]{edge[1] - 1, edge[2]});
            graph.get(edge[1] - 1).add(new int[]{edge[0] - 1, edge[2]});
        }

        // Initialize the distance array with infinity
        int[] distances = new int[vertices];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start - 1] = 0; // Distance to the start node is 0

        // Priority queue to get the node with the minimum distance
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[]{start - 1, 0});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            int currentDistance = current[1];

            // Skip if the distance is not the most updated
            if (currentDistance > distances[node]) continue;

            // Explore neighbors
            for (int[] neighbor : graph.get(node)) {
                int nextNode = neighbor[0];
                int weight = neighbor[1];
                int newDist = currentDistance + weight;

                // If a shorter path is found
                if (newDist < distances[nextNode]) {
                    distances[nextNode] = newDist;
                    pq.add(new int[]{nextNode, newDist});
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        int vertices = 4;
        List<int[]> edges = Arrays.asList(
            new int[]{1, 2, 4},
            new int[]{1, 3, 1},
            new int[]{2, 4, 2},
            new int[]{3, 4, 3}
        );
        int start = 1;

        int[] shortestPaths = dijkstra(vertices, edges, start);
        System.out.println(Arrays.toString(shortestPaths));
    }
}
