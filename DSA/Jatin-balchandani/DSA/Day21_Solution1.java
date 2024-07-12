import java.util.*;

public class Day21_Solution1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Calculate MST using Prim's algorithm
        long mstCost = primMSTCost(n, A);

        System.out.println(mstCost);
    }

    private static long primMSTCost(int n, int[] A) {
        long[] minWeight = new long[n];
        Arrays.fill(minWeight, Long.MAX_VALUE);
        minWeight[0] = 0; // Start with node 0

        boolean[] inMST = new boolean[n];

        long mstCost = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(n, Comparator.comparingLong(key -> minWeight[key]));
        pq.offer(0); // Start from node 0

        while (!pq.isEmpty()) {
            int u = pq.poll();
            if (inMST[u]) continue;

            inMST[u] = true;
            mstCost += minWeight[u];

            // Update adjacent nodes
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && u != v) {
                    long weight = Math.abs((u + 1) * (v + 1) - A[u] % A[v] - A[v] % A[u]);
                    if (weight < minWeight[v]) {
                        minWeight[v] = weight;
                        pq.offer(v);
                    }
                }
            }
        }

        return mstCost;
    }
}
