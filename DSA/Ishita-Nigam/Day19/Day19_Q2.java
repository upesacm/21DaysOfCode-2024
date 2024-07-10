import java.util.*;

public class Day19_Q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < nodes; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

       
        int start = scanner.nextInt() - 1;

        
        List<Integer> dfsOrder = dfs(graph, nodes, start);
        for (int node : dfsOrder) {
            System.out.print((node + 1) + " ");
        }
    }

    private static List<Integer> dfs(List<List<Integer>> graph, int nodes, int start) {
        List<Integer> dfsOrder = new ArrayList<>();
        boolean[] visited = new boolean[nodes];
        Stack<Integer> stack = new Stack<>();

        stack.push(start);

        while (!stack.isEmpty()) {
            int current = stack.pop();

            if (!visited[current]) {
                visited[current] = true;
                dfsOrder.add(current);

                // Add all adjacent nodes to the stack
                for (int neighbor : graph.get(current)) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }

        return dfsOrder;
    }
}
