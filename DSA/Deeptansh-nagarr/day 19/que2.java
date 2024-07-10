import java.util.*;

public class DepthFirstSearch {
    public static void dfs(int startNode, boolean[] visited, List<List<Integer>> graph, List<Integer> result) {
        visited[startNode] = true;
        result.add(startNode + 1);
        for (int neighbor : graph.get(startNode)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, graph, result);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int m = sc.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        System.out.println("Enter the edges (node1 node2): ");
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        System.out.print("Enter the starting node: ");
        int startNode = sc.nextInt() - 1;
        boolean[] visited = new boolean[n];
        List<Integer> result = new ArrayList<>();
        dfs(startNode, visited, graph, result);
        System.out.println("DFS Order: " + result);
    }
}
