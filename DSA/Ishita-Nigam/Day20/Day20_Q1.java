import java.util.*;

public class Day20_Q1 {

    public static boolean isBipartite(List<Integer>[] graph, int vertices) {
        int[] colors = new int[vertices];
        Arrays.fill(colors, -1);

        for (int i = 0; i < vertices; i++) {
            if (colors[i] == -1) {
                if (!isBipartiteComponent(graph, colors, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isBipartiteComponent(List<Integer>[] graph, int[] colors, int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        colors[start] = 0;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph[node]) {
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

    public static void main(String[] args) {
        int vertices = 4;
        int edgesCount = 4;

        List<Integer>[] graph = new List[vertices];
        for (int i = 0; i < vertices; i++) {
            graph[i] = new ArrayList<>();
        }

        // Adding edges to the graph (converting 1-based to 0-based index)
        graph[0].add(1);
        graph[1].add(0);
        graph[0].add(2);
        graph[2].add(0);
        graph[1].add(3);
        graph[3].add(1);
        graph[2].add(3);
        graph[3].add(2);

        boolean result = isBipartite(graph, vertices);

        if (result) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
