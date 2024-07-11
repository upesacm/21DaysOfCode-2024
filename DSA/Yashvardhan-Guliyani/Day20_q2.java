import java.util.*;

class Edge {
    int dest, weight;
    
    Edge(int dest, int weight) {
        this.dest = dest;
        this.weight = weight;
    }
}

public class DijkstraAlgorithm {
    private int V;
    private List<List<Edge>> adj;
    
    public DijkstraAlgorithm(int v) {
        V = v;
        adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }
    
    public void addEdge(int src, int dest, int weight) {
        adj.get(src).add(new Edge(dest, weight));
        adj.get(dest).add(new Edge(src, weight)); 
    }
    
    public int[] dijkstra(int start) {
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;
        
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
        pq.offer(new Edge(start, 0));
        
        while (!pq.isEmpty()) {
            Edge curr = pq.poll();
            int u = curr.dest;
            
            if (curr.weight > distance[u]) continue;
            
            for (Edge e : adj.get(u)) {
                int v = e.dest;
                int weight = e.weight;
                
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.offer(new Edge(v, distance[v]));
                }
            }
        }
        
        return distance;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();
        
        DijkstraAlgorithm graph = new DijkstraAlgorithm(V);
        
        System.out.println("Enter the edges (source destination weight):");
        for (int i = 0; i < E; i++) {
            int src = scanner.nextInt() - 1; 
            int dest = scanner.nextInt() - 1;
            int weight = scanner.nextInt();
            graph.addEdge(src, dest, weight);
        }
        
        System.out.print("Enter the starting node: ");
        int start = scanner.nextInt() - 1;
        
        int[] shortestDistances = graph.dijkstra(start);
        
        System.out.println("Shortest distances from node " + (start + 1) + ":");
        for (int i = 0; i < V; i++) {
            System.out.print(shortestDistances[i] + " ");
        }
        
        scanner.close();
    }
}
