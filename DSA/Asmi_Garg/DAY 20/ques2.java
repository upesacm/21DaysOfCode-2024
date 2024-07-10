import java.util.*;

public class DijkstraAlgorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int weight = sc.nextInt();
            graph.get(u).add(new Node(v, weight));
            graph.get(v).add(new Node(u, weight));
        }
        int start = sc.nextInt();
        int[] distances = dijkstra(graph, vertices, start);
        for (int i = 1; i <= vertices; i++) {
            System.out.print(distances[i] + " ");
        }
    }

    private static int[] dijkstra(List<List<Node>> graph, int vertices, int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>(vertices, Comparator.comparingInt(node -> node.weight));
        int[] distances = new int[vertices + 1];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;
        pq.add(new Node(start, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            for (Node neighbor : graph.get(node.vertex)) {
                int newDist = distances[node.vertex] + neighbor.weight;
                if (newDist < distances[neighbor.vertex]) {
                    distances[neighbor.vertex] = newDist;
                    pq.add(new Node(neighbor.vertex, newDist));
                }
            }
        }
        return distances;
    }

    static class Node {
        int vertex, weight;

        Node(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }
}
