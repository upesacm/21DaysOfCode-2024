import java.util.*;

class Day20_Q2 {
    static class Edge {
        int target, weight;

        Edge(int target, int weight) {
            this.target = target;
            this.weight = weight;
        }
    }

    public static int[] dijkstra(int vertices, List<Edge>[] graph, int start) {
        int[] distances = new int[vertices];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.weight));
        pq.add(new Edge(start, 0));

        while (!pq.isEmpty()) {
            Edge current = pq.poll();
            int currentNode = current.target;

            for (Edge edge : graph[currentNode]) {
                int newDist = distances[currentNode] + edge.weight;
                if (newDist < distances[edge.target]) {
                    distances[edge.target] = newDist;
                    pq.add(new Edge(edge.target, newDist));
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        int vertices = 4;
        int edgesCount = 4;
        int startNode = 0;

        List<Edge>[] graph = new List[vertices];
        for (int i = 0; i < vertices; i++) {
            graph[i] = new ArrayList<>();
        }

        graph[0].add(new Edge(1, 4));
        graph[0].add(new Edge(2, 1));
        graph[1].add(new Edge(3, 2));
        graph[2].add(new Edge(3, 3));

        int[] distances = dijkstra(vertices, graph, startNode);

        System.out.println("Shortest path distances from node " + (startNode + 1) + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("To node " + (i + 1) + ": " + distances[i]);
        }
    }
}
