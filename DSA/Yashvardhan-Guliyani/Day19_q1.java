import java.util.*;

public class ShortestReachBFS {
    private int nodes;
    private List<List<Integer>> adjacencyList;

    public ShortestReachBFS(int n) {
        this.nodes = n;
        this.adjacencyList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjacencyList.get(u).add(v);
        adjacencyList.get(v).add(u);
    }

    public int[] shortestReach(int start) {
        int[] distances = new int[nodes];
        Arrays.fill(distances, -1);
        distances[start] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int neighbor : adjacencyList.get(current)) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[current] + 1;
                    queue.offer(neighbor);
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
      
        int n = 6; 
        int m = 8; 
        int[][] edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {2, 4}, {4, 5}};
        int start = 0; 
        
        ShortestReachBFS graph = new ShortestReachBFS(n);

        for (int[] edge : edges) {
            graph.addEdge(edge[0], edge[1]);
        }

        int[] result = graph.shortestReach(start);

        System.out.println("Shortest reach from node " + start + " to all other nodes:");
        for (int i = 0; i < n; i++) {
            System.out.println("Node " + i + ": " + result[i]);
        }
    }
}
