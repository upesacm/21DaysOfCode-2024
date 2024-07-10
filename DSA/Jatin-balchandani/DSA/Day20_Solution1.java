import java.util.*;

public class Day20_Solution1 {
    public static String isBipartite(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        int[] color = new int[vertices + 1];
        Arrays.fill(color, -1);

        for (int i = 1; i <= vertices; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(graph, color, i)) {
                    return "NO";
                }
            }
        }

        return "YES";
    }

    private static boolean bfsCheck(List<List<Integer>> graph, int[] color, int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        color[start] = 0;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue.add(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        int vertices = 4;
        int[][] edges = { {1, 2}, {1, 3}, {2, 4}, {3, 4} };
        System.out.println(isBipartite(vertices, edges)); // Output: YES
    }
}
