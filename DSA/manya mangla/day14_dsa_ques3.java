import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] data = new int[m][2];
        for (int i = 0; i < m; i++) {
            data[i][0] = sc.nextInt();
            data[i][1] = sc.nextInt();
        }

        List<Integer> result = getLexicographicalOrder(n, data);
        for (int horse : result) {
            System.out.print(horse + " ");
        }
    }

    public static List<Integer> getLexicographicalOrder(int n, int[][] data) {
        List<Integer>[] graph = new ArrayList[n];
        int[] inDegree = new int[n];

        // Initialize adjacency list and in-degree array
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // Build the graph and calculate in-degrees
        for (int[] edge : data) {
            int from = edge[0];
            int to = edge[1];
            graph[from].add(to);
            inDegree[to]++;
        }

        // Use a priority queue to maintain lexicographical order
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                pq.add(i);
            }
        }

        // Result list to store the lexicographical order
        List<Integer> order = new ArrayList<>();
        
        // Process the priority queue
        while (!pq.isEmpty()) {
            int current = pq.poll();
            order.add(current);
            // Process all neighbors of 'current'
            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    pq.add(neighbor);
                }
            }
        }

        return order;
    }
}
