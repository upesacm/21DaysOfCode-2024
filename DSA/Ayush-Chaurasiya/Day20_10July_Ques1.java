import java.util.*;

class Graph {
    private int vertices;
    private List<Integer>[] adjacencyList;

    public Graph(int vertices) {
        this.vertices = vertices;
        adjacencyList = new ArrayList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacencyList[i] = new ArrayList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjacencyList[u].add(v);
        adjacencyList[v].add(u);
    }

    public boolean isBipartite() {
        int[] colors = new int[vertices];
        Arrays.fill(colors, -1);

        for (int i = 0; i < vertices; i++) {
            if (colors[i] == -1) {
                if (!bfsCheck(i, colors)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean bfsCheck(int src, int[] colors) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        colors[src] = 1;

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : adjacencyList[node]) {
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

public class Day20_10July_Ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        Graph graph = new Graph(vertices);

        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        scanner.close();

        if (graph.isBipartite()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
