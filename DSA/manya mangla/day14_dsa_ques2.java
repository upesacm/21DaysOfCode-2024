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

        List<Integer> result = getLexicographicalOrder(n, m, data);
        for (int horse : result) {
            System.out.print(horse + " ");
        }
    }

    public static List<Integer> getLexicographicalOrder(int n, int m, int[][] data) {
        List<Integer>[] graph = new ArrayList[n];
        int[] inDegree = new int[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] edge : data) {
            int u = edge[0];
            int v = edge[1];
            graph[u].add(v);
            inDegree[v]++;
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                pq.add(i);
            }
        }
        
        List<Integer> order = new ArrayList<>();
        while (!pq.isEmpty()) {
            int node = pq.poll();
            order.add(node);
            for (int neighbor : graph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    pq.add(neighbor);
                }
            }
        }
        
        return order;
    }
}
