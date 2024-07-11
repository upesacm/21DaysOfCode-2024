import java.util.*;

public class Day20_Solution2 {
    public static int[] dijkstra(int vertices, int[][] edges, int start) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(new int[] {edge[1], edge[2]});
            graph.get(edge[1]).add(new int[] {edge[0], edge[2]});
        }

        int[] distances = new int[vertices + 1];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;

        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        priorityQueue.add(new int[] {start, 0});

        while (!priorityQueue.isEmpty()) {
            int[] current = priorityQueue.poll();
            int currentNode = current[0];
            int currentDistance = current[1];

            if (currentDistance > distances[currentNode]) {
                continue;
            }

            for (int[] neighbor : graph.get(currentNode)) {
                int nextNode = neighbor[0];
                int edgeWeight = neighbor[1];
                int newDistance = currentDistance + edgeWeight;

                if (newDistance < distances[nextNode]) {
                    distances[nextNode] = newDistance;
                    priorityQueue.add(new int[] {nextNode, newDistance});
                }
            }
        }

        for (int i = 1; i <= vertices; i++) {
            if (distances[i] == Integer.MAX_VALUE) {
                distances[i] = -1;
            }
        }

        return Arrays.copyOfRange(distances, 1, vertices + 1);
    }

    public static void main(String[] args) {
        int vertices = 4;
        int[][] edges = { {1, 2, 4}, {1, 3, 1}, {2, 4, 2}, {3, 4, 3} };
        int start = 1;
        int[] result = dijkstra(vertices, edges, start);
        System.out.println(Arrays.toString(result)); // Output: [0, 4, 1, 4]
    }
}
