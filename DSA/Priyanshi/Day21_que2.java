import java.io.*;
import java.util.*;

public class Solution {
    static List<List<Integer>> adj;
    static int[] A;
    static int N;

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
         Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        
        adj = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int i = 0; i < N - 1; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        
        sc.close();

        System.out.println(calculateDistanceSum());
        
    }
    public static int bfs(int src, Map<Integer, List<Integer>> valueToNodes) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N];
        int[] distance = new int[N];
        
        queue.offer(src);
        visited[src] = true;
        
        int sum = 0;
        int value = A[src];
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    queue.offer(neighbor);
                    if (A[neighbor] == value) {
                        sum += distance[neighbor];
                    }
                }
            }
        }
        
        return sum;
    }
    
    public static int calculateDistanceSum() {
        Map<Integer, List<Integer>> valueToNodes = new HashMap<>();
        for (int i = 0; i < N; i++) {
            valueToNodes.computeIfAbsent(A[i], k -> new ArrayList<>()).add(i);
        }

        int totalSum = 0;

        for (List<Integer> nodes : valueToNodes.values()) {
            for (int node : nodes) {
                totalSum += bfs(node, valueToNodes);
            }
        }

        return totalSum / 2;  
    }
}
