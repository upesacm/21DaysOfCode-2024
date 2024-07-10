import java.util.*;

class GraphDFS {
    private int nodes;
    private LinkedList<Integer>[] adjacencyList;
    private boolean[] visited;

    public GraphDFS(int nodes) {
        this.nodes = nodes;
        adjacencyList = new LinkedList[nodes];
        visited = new boolean[nodes];
        for (int i = 0; i < nodes; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int u, int v) {
        adjacencyList[u].add(v);
        adjacencyList[v].add(u);
    }

    public void dfs(int start, List<Integer> result) {
        visited[start] = true;
        result.add(start);

        for (int neighbor : adjacencyList[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, result);
            }
        }
    }
}

public class Day19_09July_Ques2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        GraphDFS graph = new GraphDFS(nodes);

        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        int startNode = scanner.nextInt();
        List<Integer> result = new ArrayList<>();
        graph.dfs(startNode, result);

        for (int node : result) {
            System.out.print(node + " ");
        }
    }
}
