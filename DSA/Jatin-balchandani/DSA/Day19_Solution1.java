import java.util.*;

public class Day19_Solution1 {
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

        public int[] bfsShortestReach(int start) {
            int[] distances = new int[numNodes];
            Arrays.fill(distances, -1);
            distances[start] = 0;

            Queue<Integer> queue = new LinkedList<>();
            queue.offer(start);

            while (!queue.isEmpty()) {
                int current = queue.poll();
                for (int neighbor : adjList.get(current)) {
                    if (distances[neighbor] == -1) {
                        distances[neighbor] = distances[current] + 1;
                        queue.offer(neighbor);
                    }
                }
            }

            return distances;
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

        int[] distances = graph.bfsShortestReach(startNode);

        for (int i = 0; i < distances.length; i++) {
            if (i != startNode) {
                System.out.print(distances[i] + " ");
            }
        }
    }
}
