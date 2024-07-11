import java.util.*;

public class Day19_Q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < nodes; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        int start = scanner.nextInt() - 1;
        int[] distances = bfs(graph, nodes, start);
        for (int i = 0; i < nodes; i++) {
            if (i != start) {
                System.out.print((distances[i] == -1 ? -1 : distances[i] * 6) + " ");
            }
        }
    }
    
    private static int[] bfs(List<List<Integer>> graph, int nodes, int start) {
        int[] distances = new int[nodes];
        Arrays.fill(distances, -1);
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        distances[start] = 0;
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int neighbor : graph.get(current)) {
                if (distances[neighbor] == -1) {
                    queue.add(neighbor);
                    distances[neighbor] = distances[current] + 1;
                }
            }
        }
        
        return distances;
    }
}
