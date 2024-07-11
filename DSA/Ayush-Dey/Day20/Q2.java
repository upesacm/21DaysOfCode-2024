//Question - 1
//Author - Ayush Dey

import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int v = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = sc.nextInt();
        List<int[]> edges = new ArrayList<>();
        System.out.println("Enter the edges (u, v, weight):");
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int weight = sc.nextInt();
            edges.add(new int[]{u, v, weight});
        }
        System.out.print("Enter the starting node: ");
        int start = sc.nextInt();
        int[] dist = dijkstra(v, edges, start);
        System.out.println("Shortest distances from node " + start + ":");
        for (int i = 0; i < v; i++) {
            System.out.print(dist[i] + " ");
        }
    }

    static int[] dijkstra(int v, List<int[]> edges, int start) {
        int[] dist = new int[v];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start - 1] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, start});
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[1];
            for (int[] edge : edges) {
                if (edge[0] == node) {
                    int neighbor = edge[1];
                    int weight = edge[2];
                    if (dist[neighbor - 1] > dist[node - 1] + weight) {
                        dist[neighbor - 1] = dist[node - 1] + weight;
                        pq.add(new int[]{dist[neighbor - 1], neighbor});
                    }
                } else if (edge[1] == node) {
                    int neighbor = edge[0];
                    int weight = edge[2];
                    if (dist[neighbor - 1] > dist[node - 1] + weight) {
                        dist[neighbor - 1] = dist[node - 1] + weight;
                        pq.add(new int[]{dist[neighbor - 1], neighbor});
                    }
                }
            }
        }
        return dist;
    }
}