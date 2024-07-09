import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < nodes; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        int start = scanner.nextInt();
        
        int[] distances = bfs(graph, start);
        for (int i = 0; i < nodes; i++) {
            System.out.print(distances[i] + " ");
        }
    }

    public static int[] bfs(List<List<Integer>> graph, int start) {
        int nodes = graph.size();
        int[] distances = new int[nodes];
        Arrays.fill(distances, -1);
        distances[start] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[node] + 1;
                    queue.add(neighbor);
                }
            }
        }
        
        return distances;
    }
}


// Input :
//   5 6
//   0 1
//   0 2
//   1 3
//   1 4
//   2 4
//   3 4
//   0


// Output : 
// 0 1 1 2 2
