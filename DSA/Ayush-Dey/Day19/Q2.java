// Question - 1
//Author _ Ayush Dey

import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // number of nodes
        int m = sc.nextInt(); // number of edges
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            edges.add(new int[]{sc.nextInt(), sc.nextInt()});
        }
        int start = sc.nextInt(); // starting node

        boolean[] visited = new boolean[n];
        List<Integer> dfsOrder = new ArrayList<>();

        dfs(n, edges, start, visited, dfsOrder);

        for (int node : dfsOrder) {
            System.out.print(node + " ");
        }
    }

    public static void dfs(int n, List<int[]> edges, int node, boolean[] visited, List<Integer> dfsOrder) {
        visited[node - 1] = true;
        dfsOrder.add(node);

        for (int[] edge : edges) {
            if (edge[0] == node && !visited[edge[1] - 1]) {
                dfs(n, edges, edge[1], visited, dfsOrder);
            }
            if (edge[1] == node && !visited[edge[0] - 1]) {
                dfs(n, edges, edge[0], visited, dfsOrder);
            }
        }
    }
}