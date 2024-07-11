import java.util.*;

public class BipartiteCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        System.out.println(isBipartite(graph, vertices) ? "YES" : "NO");
    }

    private static boolean isBipartite(List<List<Integer>> graph, int vertices) {
        int[] colors = new int[vertices + 1];
        Arrays.fill(colors, -1);
        for (int i = 1; i <= vertices; i++) {
            if (colors[i] == -1) {
                if (!bfsCheck(graph, i, colors)) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean bfsCheck(List<List<Integer>> graph, int src, int[] colors) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        colors[src] = 1;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[node];
                    queue.add(neighbor);
                } else if (colors[neighbor] == colors[node]) {
                    return false;
                }
            }
        }
        return true;
    }
}
