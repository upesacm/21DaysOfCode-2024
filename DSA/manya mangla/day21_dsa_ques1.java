import java.io.*;
import java.util.*;

public class Solution {

    static class Edge implements Comparable<Edge> {
        int u;
        int v;
        int weight;

        public Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static int[] parent;
    static int[] rank;

    // Find with path compression
    static int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    // Union by rank
    static void union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }

    static int calculateEdgeWeight(int x, int y, int[] A) {
        return Math.abs(x * y - A[x] % A[y] - A[y] % A[x]);
    }

    static int minimumSpanningTreeCost(int N, int[] A) {
        List<Edge> edges = new ArrayList<>();

        // Generate all edges and their weights
        for (int x = 1; x <= N; x++) {
            for (int y = x + 1; y <= N; y++) {
                int weight = calculateEdgeWeight(x, y, A);
                edges.add(new Edge(x - 1, y - 1, weight)); // Convert 1-indexed to 0-indexed
            }
        }

        // Sort edges based on weight
        Collections.sort(edges);

        parent = new int[N];
        rank = new int[N];

        // Initialize parent and rank arrays for union-find
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int mstCost = 0;
        int edgesInMst = 0;

        // Apply Kruskal's algorithm
        for (Edge edge : edges) {
            if (find(edge.u) != find(edge.v)) {
                union(edge.u, edge.v);
                mstCost += edge.weight;
                edgesInMst++;
                if (edgesInMst == N - 1) {
                    break; // Found all edges needed for MST
                }
            }
        }

        return mstCost;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] A = new int[N + 1]; // A[0] will be unused

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int result = minimumSpanningTreeCost(N, A);
        System.out.println(result);
    }
}
