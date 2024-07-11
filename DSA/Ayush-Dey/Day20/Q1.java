//Question - 1
//Author - Ayush Dey

import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        int v = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = sc.nextInt();
        List<int[]> edges = new ArrayList<>();
        System.out.println("Enter the edges (u, v):");
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(new int[]{u, v});
        }
        System.out.println(canBeColored(v, edges)? "YES" : "NO");
    }

    static boolean canBeColored(int v, List<int[]> edges) {
        int[] color = new int[v + 1];
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0 &&!dfs(i, 1, color, edges)) {
                return false;
            }
        }
        return true;
    }

    static boolean dfs(int node, int c, int[] color, List<int[]> edges) {
        color[node] = c;
        for (int[] edge : edges) {
            if (edge[0] == node) {
                if (color[edge[1]] == c) return false;
                if (color[edge[1]] == 0 &&!dfs(edge[1], 3 - c, color, edges)) return false;
            } else if (edge[1] == node) {
                if (color[edge[0]] == c) return false;
                if (color[edge[0]] == 0 &&!dfs(edge[0], 3 - c, color, edges)) return false;
            }
        }
        return true;
    }
}