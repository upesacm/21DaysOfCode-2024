import java.util.*;

public class Main {
    static int[] color;
    static List<List<Integer>> graph;
    static boolean isBipartite;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        color = new int[vertices + 1];
        isBipartite = true;
        for (int i = 1; i <= vertices; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        System.out.println(isBipartite ? "YES" : "NO");
    }

    static void dfs(int node, int c) {
        color[node] = c;
        for (int neighbor : graph.get(node)) {
            if (color[neighbor] == 0) {
                dfs(neighbor, 3 - c);
            } else if (color[neighbor] == c) {
                isBipartite = false;
                return;
            }
        }
    }
}


// Input :
//   4 4
//   1 2
//   1 3
//   2 4
//   3 4


// Output : 
// YES
