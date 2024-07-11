import java.io.*;
import java.util.*;

public class Solution {

    static class Edge {
        int u, v;
        Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    static int[] parent;
    static int[] depth;
    static List<Edge>[] graph;
    static int[] a;

    static void dfs(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        for (Edge e : graph[u]) {
            if (e.v != p) {
                dfs(e.v, u, d + 1);
            }
        }
    }

    static int lca(int u, int v) {
        while (depth[u] > depth[v]) {
            u = parent[u];
        }
        while (depth[v] > depth[u]) {
            v = parent[v];
        }
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        graph = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u].add(new Edge(u, v));
            graph[v].add(new Edge(v, u));
        }
        a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        parent = new int[n + 1];
        depth = new int[n + 1];
        dfs(1, 0, 0);
        long ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j]) {
                    int l = lca(i, j);
                    ans += depth[i] + depth[j] - 2 * depth[l];
                }
            }
        }
        System.out.println(ans);
    }
}
