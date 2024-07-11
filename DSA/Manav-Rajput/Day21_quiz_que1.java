import java.io.*;
import java.util.*;

public class Solution {

    static class Edge implements Comparable<Edge> {
        int u, v, weight;

        Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static class UnionFind {
        int[] parent, rank;

        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        boolean union(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                return false;
            }
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N + 1]; // 1-indexed array
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }

        List<Edge> edges = new ArrayList<>();

        // Generating all edges
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int weight = Math.abs(i * j - A[i] % A[j] - A[j] % A[i]);
                edges.add(new Edge(i, j, weight));
            }
        }

        // Sorting edges by their weights
        Collections.sort(edges);

        // Applying Kruskal's algorithm
        UnionFind uf = new UnionFind(N + 1);
        int mstCost = 0;
        int edgesUsed = 0;

        for (Edge edge : edges) {
            if (uf.union(edge.u, edge.v)) {
                mstCost += edge.weight;
                edgesUsed++;
                if (edgesUsed == N - 1) {
                    break;
                }
            }
        }

        System.out.println(mstCost);
    }
}
