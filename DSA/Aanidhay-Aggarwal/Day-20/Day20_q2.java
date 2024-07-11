import java.util.*;

public class Main {
    static class Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.get(u).add(new Edge(v, weight));
        }
        int start = scanner.nextInt();
        int[] distance = new int[vertices + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> distance[a] - distance[b]);
        queue.add(start);
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (Edge edge : graph.get(node)) {
                if (distance[node] + edge.weight < distance[edge.to]) {
                    distance[edge.to] = distance[node] + edge.weight;
                    queue.add(edge.to);
                }
            }
        }
        for (int i = 1; i <= vertices; i++) {
            System.out.print(distance[i] + " ");
        }
    }
}


// Input :
//   4 4
//   1 2 4
//   1 3 1
//   2 4 2
//   3 4 3
//   1


// Output : 
// 0 4 1 4
