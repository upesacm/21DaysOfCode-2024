import java.util.*;

class Graph {
    private int nodes;
    private LinkedList<Integer>[] adjacencyList;

    public Graph(int nodes) {
        this.nodes = nodes;
        adjacencyList = new LinkedList[nodes];
        for (int i = 0; i < nodes; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjacencyList[u].add(v);
        adjacencyList[v].add(u);
    }

    public int[] bfsShortestReach(int start) {
        int[] distances = new int[nodes];
        Arrays.fill(distances, -1); 
        boolean[] visited = new boolean[nodes];
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;
        distances[start] = 0;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : adjacencyList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distances[neighbor] = distances[node] + 1;
                    queue.add(neighbor);
                }
            }
        }
        return distances;
    }
}

public class Day19_09July_Ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        Graph graph = new Graph(nodes);

        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        int startNode = scanner.nextInt();
        int[] distances = graph.bfsShortestReach(startNode);

        for (int distance : distances) {
            System.out.print(distance + " ");
        }
        scanner.close();
    }
}
