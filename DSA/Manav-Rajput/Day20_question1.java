package new2;

import java.util.*;

public class BipartiteGraph {
    static class Graph {
        private int vertices;
        private List<List<Integer>> adjList;

        public Graph(int vertices) {
            this.vertices = vertices;
            adjList = new ArrayList<>(vertices);
            for (int i = 0; i < vertices; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        public void addEdge(int src, int dest) {
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                adjList.get(src).add(dest);
                adjList.get(dest).add(src);
            } else {
                System.out.println("Invalid edge: (" + src + ", " + dest + ")");
            }
        }

        public boolean isBipartite() {
            int[] color = new int[vertices];
            Arrays.fill(color, -1);

            for (int i = 0; i < vertices; i++) {
                if (color[i] == -1) {
                    if (!bfsCheck(i, color)) {
                        return false;
                    }
                }
            }
            return true;
        }

        private boolean bfsCheck(int src, int[] color) {
            Queue<Integer> queue = new LinkedList<>();
            queue.add(src);
            color[src] = 1;

            while (!queue.isEmpty()) {
                int node = queue.poll();

                for (int neighbor : adjList.get(node)) {
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
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter number of vertices:");
        int vertices = scanner.nextInt();
        
        System.out.println("Enter number of edges:");
        int edges = scanner.nextInt();

        Graph graph = new Graph(vertices);

        System.out.println("Enter edges (src dest):");
        for (int i = 0; i < edges; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            graph.addEdge(src, dest);
        }

        if (graph.isBipartite()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}
