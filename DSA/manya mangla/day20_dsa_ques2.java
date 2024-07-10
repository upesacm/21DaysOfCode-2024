import java.util.*;

public class DijkstraShortestPath {
    
    public static int[] dijkstra(int numVertices, int[][] edges, int startNode) {
        // Step 1: Create adjacency list representation of the graph
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= numVertices; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph.get(u).add(new Edge(v, weight));
            graph.get(v).add(new Edge(u, weight)); // Since it's an undirected graph
        }
        
        // Step 2: Initialize distances array with infinity (Integer.MAX_VALUE)
        int[] distances = new int[numVertices + 1];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[startNode] = 0;
        
        // Step 3: Use a priority queue (min-heap) to get the node with the smallest distance
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.distance));
        pq.offer(new Node(startNode, 0));
        
        // Step 4: Process nodes until the priority queue is empty
        while (!pq.isEmpty()) {
            Node currentNode = pq.poll();
            int u = currentNode.vertex;
            
            // If the extracted vertex is already processed, skip
            if (currentNode.distance > distances[u]) {
                continue;
            }
            
            // Process each neighbor of u
            for (Edge neighbor : graph.get(u)) {
                int v = neighbor.destination;
                int weightUV = neighbor.weight;
                // Calculate new distance
                int newDistance = distances[u] + weightUV;
                
                // If a shorter path to v is found, update distance and add to priority queue
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    pq.offer(new Node(v, newDistance));
                }
            }
        }
        
        // Return the shortest path distances from startNode to all other nodes
        return distances;
    }
    
    // Edge class to represent an edge with destination vertex and weight
    static class Edge {
        int destination;
        int weight;
        
        public Edge(int destination, int weight) {
            this.destination = destination;
            this.weight = weight;
        }
    }
    
    // Node class to represent a vertex with its current distance from the startNode
    static class Node {
        int vertex;
        int distance;
        
        public Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }
    
    public static void main(String[] args) {
        int numVertices = 4;
        int[][] edges = {{1, 2, 4}, {1, 3, 1}, {2, 4, 2}, {3, 4, 3}};
        int startNode = 1;
        
        int[] shortestDistances = dijkstra(numVertices, edges, startNode);
        System.out.println(Arrays.toString(shortestDistances)); // Output: [0, 4, 1, 4]
    }
}
