import java.util.*;

public class GraphColoring {
    private int V; 
    private List<List<Integer>> adj; 

    public GraphColoring(int v) {
        V = v;
        adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    public void addEdge(int v, int w) {
        adj.get(v).add(w);
        adj.get(w).add(v);
    }

    public boolean isBipartite() {
        int[] colors = new int[V];
        Arrays.fill(colors, -1);

        for (int i = 0; i < V; i++) {
            if (colors[i] == -1) {
                if (!colorGraph(i, colors, 0)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean colorGraph(int v, int[] colors, int color) {
        colors[v] = color;

        for (int adjacent : adj.get(v)) {
            if (colors[adjacent] == -1) {
                if (!colorGraph(adjacent, colors, 1 - color)) {
                    return false;
                }
            } else if (colors[adjacent] == color) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();
        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        GraphColoring graph = new GraphColoring(V);

        System.out.println("Enter the edges (format: vertex1 vertex2):");
        for (int i = 0; i < E; i++) {
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            graph.addEdge(v - 1, w - 1);  
        }

        System.out.println(graph.isBipartite() ? "YES" : "NO");
    }
}
