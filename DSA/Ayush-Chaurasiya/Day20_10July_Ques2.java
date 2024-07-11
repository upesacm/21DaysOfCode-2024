import java.util.*;

class Graph {
    private int vertices;
    private List<List<Node>> adjacencyList;

    class Node implements Comparable<Node> {
        int vertex, weight;

        Node(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    public Graph(int vertices) {
        this.vertices = vertices;
        adjacencyList = new ArrayList<>(vertices);
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v, int weight) {
        adjacencyList.get(u).add(new Node(v, weight));
        adjacencyList.get(v).add(new Node(u, weight));
    }

    public int[] dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] distances = new int[vertices];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            int u = current.vertex;

            for (Node neighbor : adjacencyList.get(u)) {
                int v = neighbor.vertex;
                int weight = neighbor.weight;

                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.add(new Node(v, distances[v]));
                }
            }
        }

        return distances;
    }
}

public class Day20_10July_Ques2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        Graph graph = new Graph(vertices);

        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            int weight = scanner.nextInt();
            graph.addEdge(u, v, weight);
        }

        int start = scanner.nextInt() - 1;
        scanner.close();

        int[] distances = graph.dijkstra(start);

        System.out.println(Arrays.toString(distances));
    }
}
