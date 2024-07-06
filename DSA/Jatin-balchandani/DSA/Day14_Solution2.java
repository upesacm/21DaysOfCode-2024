
import java.util.*;

public class Day14_Solution2 {

    static class Graph {
        int V;
        List<Integer>[] adj;
        int[] indegree;

        public Graph(int V) {
            this.V = V;
            adj = new ArrayList[V];
            for (int i = 0; i < V; i++) {
                adj[i] = new ArrayList<>();
            }
            indegree = new int[V];
        }

        public void addEdge(int u, int v) {
            adj[u].add(v);
            indegree[v]++;
        }

        public List<Integer> topologicalSort() {
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    pq.add(i);
                }
            }

            List<Integer> result = new ArrayList<>();
            while (!pq.isEmpty()) {
                int u = pq.poll();
                result.add(u);

                for (int v : adj[u]) {
                    if (--indegree[v] == 0) {
                        pq.add(v);
                    }
                }
            }

            return result;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt(); // number of horses
        int m = scanner.nextInt(); // number of pairs

        Graph graph = new Graph(n);

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph.addEdge(a, b);
        }

        List<Integer> sortedOrder = graph.topologicalSort();

        for (int horse : sortedOrder) {
            System.out.print(horse + " ");
        }
        System.out.println();

        scanner.close();
    }
}
