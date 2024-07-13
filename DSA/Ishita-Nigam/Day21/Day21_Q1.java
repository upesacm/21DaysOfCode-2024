import java.util.*;

public class Day21_Q1 {
    static class Edge {
        int node;
        int weight;

        Edge(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    public static int calculateWeight(int x, int y, int[] A) {
        return Math.abs(x * y - A[x - 1] % A[y - 1] - A[y - 1] % A[x - 1]);
    }

    public static int findMST(int N, int[] A) {
        List<List<Edge>> adjList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int weight = calculateWeight(i, j, A);
                adjList.get(i - 1).add(new Edge(j - 1, weight));
                adjList.get(j - 1).add(new Edge(i - 1, weight));
            }
        }

        // Prim's algorithm
        PriorityQueue<Edge> minHeap = new PriorityQueue<>(Comparator.comparingInt(e -> e.weight));
        boolean[] visited = new boolean[N];
        minHeap.add(new Edge(0, 0));
        int mstCost = 0;

        while (!minHeap.isEmpty()) {
            Edge edge = minHeap.poll();
            if (visited[edge.node])
                continue;
            visited[edge.node] = true;
            mstCost += edge.weight;

            for (Edge e : adjList.get(edge.node)) {
                if (!visited[e.node]) {
                    minHeap.add(e);
                }
            }
        }

        return mstCost;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        int mstCost = findMST(N, A);
        System.out.println(mstCost);
    }
}
