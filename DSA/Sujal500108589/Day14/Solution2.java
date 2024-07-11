import java.util.*;

public class Solution2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        int[][] data = new int[m][2];
        for (int i = 0; i < m; i++) {
            data[i][0] = scanner.nextInt();
            data[i][1] = scanner.nextInt();
        }
        
        int[] result = arrangeHorses(n, data);
        
        for (int i = 0; i < n; i++) {
            System.out.print(result[i] + " ");
        }
        
        scanner.close();
    }
    
    public static int[] arrangeHorses(int n, int[][] data) {
        // Graph representation and in-degree calculation
        List<Integer>[] graph = new ArrayList[n];
        int[] inDegree = new int[n];
        
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] pair : data) {
            int u = pair[0];
            int v = pair[1];
            graph[v].add(u); // Reverse the direction to find the topological order
            inDegree[u]++;
        }
        
        // Priority queue for lexicographically smallest order
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                pq.offer(i);
            }
        }
        
        // Result array to store the order
        int[] result = new int[n];
        int index = 0;
        
        while (!pq.isEmpty()) {
            int u = pq.poll();
            result[index++] = u;
            
            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    pq.offer(v);
                }
            }
        }
        
        return result;
    }
}
