import java.util.*;

public class ShortestReach {
    public static int[] bfs(int n, int[][] edges, int startNode) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            graph.get(edge[0] - 1).add(edge[1] - 1);
            graph.get(edge[1] - 1).add(edge[0] - 1);
        }
        
        int[] distances = new int[n];
        Arrays.fill(distances, -1);
        distances[startNode - 1] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(startNode - 1);
        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            for (int neighbor : graph.get(currentNode)) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[currentNode] + 1;
                    queue.offer(neighbor);
                }
            }
        }
        return distances;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int m = sc.nextInt();
        int[][] edges = new int[m][2];
        System.out.println("Enter the edges: ");
        for (int i = 0; i < m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }

        System.out.print("Enter the starting node: ");
        int startNode = sc.nextInt();
        int[] distances = bfs(n, edges, startNode);
        System.out.println("Shortest reach from node " + startNode + ":");
        for (int i = 0; i < n; i++) {
            if (i != startNode - 1) {
                System.out.println("Node " + (i + 1) + ": " + distances[i]);
            }
        }
    }
}
