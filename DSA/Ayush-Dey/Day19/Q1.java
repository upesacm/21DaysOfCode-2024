// Question - 1
//Author _ Ayush Dey

import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // number of nodes
        int m = sc.nextInt(); // number of edges
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            edges.add(new int[]{sc.nextInt(), sc.nextInt()});
        }
        int start = sc.nextInt(); // starting node

        int[] dist = bfs(n, edges, start);

        for (int i = 1; i <= n; i++) {
            if (i != start) {
                System.out.print(dist[i - 1] + " ");
            }
        }
    }

    public static int[] bfs(int n, List<int[]> edges, int start) {
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[start - 1] = 0;

        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int node = q.poll();
            for (int[] edge : edges) {
                if (edge[0] == node && dist[edge[1] - 1] == -1) {
                    dist[edge[1] - 1] = dist[node - 1] + 1;
                    q.add(edge[1]);
                }
                if (edge[1] == node && dist[edge[0] - 1] == -1) {
                    dist[edge[0] - 1] = dist[node - 1] + 1;
                    q.add(edge[0]);
                }
            }
        }

        return dist;
    }
}