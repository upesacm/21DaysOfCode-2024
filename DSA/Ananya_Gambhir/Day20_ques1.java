import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Day20_ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        int[][] graph = new int[vertices][vertices];

        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        
        if (isBipartite(graph, vertices)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }

    private static boolean isBipartite(int[][] graph, int vertices) {
        int[] colors = new int[vertices];
        for (int i = 0; i < vertices; i++) {
            colors[i] = -1; 
        }

        for (int i = 0; i < vertices; i++) {
            if (colors[i] == -1) { 
                if (!bfsCheck(graph, i, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

    private static boolean bfsCheck(int[][] graph, int start, int[] colors) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        colors[start] = 0; 

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor = 0; neighbor < graph.length; neighbor++) {
                if (graph[node][neighbor] == 1) { 
                    if (colors[neighbor] == -1) { 
                        colors[neighbor] = 1 - colors[node]; 
                        queue.add(neighbor);
                    } else if (colors[neighbor] == colors[node]) { 
                        return false; 
                    }
                }
            }
        }

        return true;
    }
}
