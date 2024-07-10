import java.util.*;

public class DepthFirstSearch {
    private int nodes;
    private List<List<Integer>> adjacencyList;

    public DepthFirstSearch(int n) {
        this.nodes = n;
        this.adjacencyList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjacencyList.get(u).add(v);
        adjacencyList.get(v).add(u);  
    }

    public List<Integer> dfs(int start) {
        boolean[] visited = new boolean[nodes];
        List<Integer> result = new ArrayList<>();
        dfsUtil(start, visited, result);
        return result;
    }

    private void dfsUtil(int v, boolean[] visited, List<Integer> result) {
        visited[v] = true;
        result.add(v);

        for (int neighbor : adjacencyList.get(v)) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, result);
            }
        }
    }

    public static void main(String[] args) {
       
        int n = 6;  
        int m = 7;  
        int[][] edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 5}, {4, 5}, {3, 5}};
        int start = 0;  

        DepthFirstSearch graph = new DepthFirstSearch(n);

        for (int[] edge : edges) {
            graph.addEdge(edge[0], edge[1]);
        }

        List<Integer> dfsOrder = graph.dfs(start);

        System.out.println("Nodes visited in DFS order starting from node " + start + ":");
        System.out.println(dfsOrder);
    }
}
