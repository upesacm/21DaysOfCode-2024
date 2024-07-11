import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        sc.close();
        System.out.println(findMSTCost(N, A));
    }
    
         // Edge class to store edges with their weights
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        // Compare edges based on their weight
        public int compareTo(Edge compareEdge) {
            return this.weight - compareEdge.weight;
        }
    }

    // Disjoint set class to manage connected components
    static class DisjointSet {
        int[] parent, rank;

        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]); 
            }
            return parent[u];
        }

        public void union(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    }

    public static int calculateWeight(int x, int y, int[] A) {
        return Math.abs(x * y - A[x - 1] % A[y - 1] - A[y - 1] % A[x - 1]);
    }

    public static int findMSTCost(int N, int[] A) {
        List<Edge> edges = new ArrayList<>();

        // Generate all edges with their weights
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int weight = calculateWeight(i, j, A);
                edges.add(new Edge(i - 1, j - 1, weight));
            }
        }

        // Sort edges based on weight
        Collections.sort(edges);

        // Initialize DisjointSet for Kruskal's algorithm
        DisjointSet ds = new DisjointSet(N);

        int mstCost = 0;
        int edgesUsed = 0;

        // Kruskal's algorithm
        for (Edge edge : edges) {
            if (ds.find(edge.src) != ds.find(edge.dest)) {
                ds.union(edge.src, edge.dest);
                mstCost += edge.weight;
                edgesUsed++;
                if (edgesUsed == N - 1) break; // Stop when we have N-1 edges
            }
        }

        return mstCost;
    }
}
