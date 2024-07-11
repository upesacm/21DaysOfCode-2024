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
        int[] color = new int[V];
        Arrays.fill(color, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfsColor(i, 0, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean dfsColor(int v, int c, int[] color) {
        color[v] = c;

        for (int neighbor : adj.get(v)) {
            if (color[neighbor] == -1) {
                if (!dfsColor(neighbor, 1 - c, color)) {
                    return false;
                }
            } else if (color[neighbor] == color[v]) {
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
        
        System.out.println("Enter the edges (vertex pairs):");
        for (int i = 0; i < E; i++) {
            int v = scanner.nextInt() - 1; 
            int w = scanner.nextInt() - 1;
            graph.addEdge(v, w);
        }
        
        System.out.println(graph.isBipartite() ? "YES" : "NO");
        
        scanner.close();
    }
}
