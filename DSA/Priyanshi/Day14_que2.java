import java.util.*;

class Day14_que2 {
    static void topologicalSort(int n, int[][] data) {
        int[] inDegree = new int[n];
        List<List<Integer>> graph = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : data) {
            graph.get(edge[0]).add(edge[1]);
            inDegree[edge[1]]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node);
            
            for (int neighbor : graph.get(node)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (result.size()!= n) {
            System.out.println("No valid order exists");
            return;
        }
        
        for (int i = result.size() - 1; i >= 0; i--) {
            System.out.print(result.get(i) + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of horses (n):");
        int n = sc.nextInt();
        System.out.println("Enter the number of comparisons (m):");
        int m = sc.nextInt();
        int[][] data = new int[m][2];
        System.out.println("Enter the comparisons:");
        for (int i = 0; i < m; i++) {
            data[i][0] = sc.nextInt();
            data[i][1] = sc.nextInt();
        }
        
        topologicalSort(n, data);
    }
}
