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
        
        boolean[] visited = new boolean[nodes];
        List<Integer> dfsOrder = new ArrayList<>();
        dfs(graph, start, visited, dfsOrder);
        
        for (int node : dfsOrder) {
            System.out.print(node + " ");
        }
    }

    public static void dfs(List<List<Integer>> graph, int node, boolean[] visited, List<Integer> dfsOrder) {
        visited[node] = true;
        dfsOrder.add(node);
        
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, visited, dfsOrder);
            }
        }
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
// 0 1 3 4 2
