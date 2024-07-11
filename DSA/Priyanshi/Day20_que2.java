import java.util.*;

public class DijkstraAlgorithm {
    static class Graph {
        private int vertices;
        private List<List<Node>> adjList;

        static class Node implements Comparable<Node> {
            int vertex;
            int weight;

            public Node(int vertex, int weight) {
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
            adjList = new ArrayList<>(vertices);
            for (int i = 0; i < vertices; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        public void addEdge(int src, int dest, int weight) {
            adjList.get(src).add(new Node(dest, weight));
            adjList.get(dest).add(new Node(src, weight)); // For undirected graph
        }

        public int[] dijkstra(int startVertex) {
            int[] distances = new int[vertices];
            Arrays.fill(distances, Integer.MAX_VALUE);
            distances[startVertex] = 0;

            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.add(new Node(startVertex, 0));

            while (!pq.isEmpty()) {
                Node node = pq.poll();
                int currentVertex = node.vertex;

                for (Node neighbor : adjList.get(currentVertex)) {
                    int newDist = distances[currentVertex] + neighbor.weight;
                    if (newDist < distances[neighbor.vertex]) {
                        distances[neighbor.vertex] = newDist;
                        pq.add(new Node(neighbor.vertex, newDist));
                    }
                }
            }

            return distances;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of vertices:");
        int vertices = scanner.nextInt();

        System.out.println("Enter number of edges:");
        int edges = scanner.nextInt();

        Graph graph = new Graph(vertices);

        System.out.println("Enter edges (src dest weight):");
        for (int i = 0; i < edges; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(src - 1, dest - 1, weight); // Convert to zero-based index
        }

        System.out.println("Enter starting vertex:");
        int startVertex = scanner.nextInt();

        int[] distances = graph.dijkstra(startVertex - 1); // Convert to zero-based index

        System.out.println("Shortest path distances from vertex " + startVertex + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("To vertex " + (i + 1) + ": " + distances[i]);
        }

        scanner.close();
    }
}
