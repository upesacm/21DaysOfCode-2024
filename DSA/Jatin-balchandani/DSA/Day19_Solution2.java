import java.util.*;

public class Day19_Solution2
{
    static class Graph {
        private int numNodes;
        private List<List<Integer>> adjList;

        public Graph(int numNodes) {
            this.numNodes = numNodes;
            adjList = new ArrayList<>(numNodes);
            for (int i = 0; i < numNodes; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        public void addEdge(int u, int v) {
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        public void dfs(int start) {
            boolean[] visited = new boolean[numNodes];
            List<Integer> dfsOrder = new ArrayList<>();
            dfsUtil(start, visited, dfsOrder);

            for (int node : dfsOrder) {
                System.out.print(node + " ");
            }
        }

        private void dfsUtil(int node, boolean[] visited, List<Integer> dfsOrder) {
            visited[node] = true;
            dfsOrder.add(node);

            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    dfsUtil(neighbor, visited, dfsOrder);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numNodes = scanner.nextInt();
        int numEdges = scanner.nextInt();

        Graph graph = new Graph(numNodes);

        for (int i = 0; i < numEdges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        int startNode = scanner.nextInt();

        graph.dfs(startNode);
    }
}
