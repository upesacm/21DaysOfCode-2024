import java.util.*;

public class TwoColorGraph {
    
    public static boolean canTwoColor(int numVertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= numVertices; i++) {
            graph.add(new ArrayList<>());
        }
        
        // Build the adjacency list
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        int[] colors = new int[numVertices + 1]; // 0 = uncolored, 1 and -1 for two colors
        
        for (int i = 1; i <= numVertices; i++) {
            if (colors[i] == 0) { // uncolored
                if (!dfs(i, 1, colors, graph)) { // try coloring with color 1
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private static boolean dfs(int node, int color, int[] colors, List<List<Integer>> graph) {
        colors[node] = color;
        
        for (int neighbor : graph.get(node)) {
            if (colors[neighbor] == 0) { // not colored
                if (!dfs(neighbor, -color, colors, graph)) {
                    return false;
                }
            } else if (colors[neighbor] == colors[node]) { // colored with the same color
                return false;
            }
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        int numVertices = 4;
        int[][] edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};
        
        boolean canTwoColor = canTwoColor(numVertices, edges);
        if (canTwoColor) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
