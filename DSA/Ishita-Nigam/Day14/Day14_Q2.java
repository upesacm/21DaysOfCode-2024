import java.util.*;

public class Day14_Q2 {

    public static int[] findOrder(int n, int[][] data) {
        List<Integer>[] adjList = new ArrayList[n];
        int[] inDegree = new int[n];

        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int[] pair : data) {
            adjList[pair[0]].add(pair[1]);
            inDegree[pair[1]]++;
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                minHeap.offer(i);
            }
        }

        int[] result = new int[n];
        int index = 0;

        while (!minHeap.isEmpty()) {
            int horse = minHeap.poll();
            result[index++] = horse;

            for (int neighbor : adjList[horse]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    minHeap.offer(neighbor);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of horses: ");
        int n = scanner.nextInt();

        System.out.print("Enter the number of relations: ");
        int m = scanner.nextInt();

        int[][] data = new int[m][2];
        System.out.println("Enter the relations (horse_a horse_b):");
        for (int i = 0; i < m; i++) {
            data[i][0] = scanner.nextInt();
            data[i][1] = scanner.nextInt();
        }

        int[] result = findOrder(n, data);
        System.out.println("Lexicographically smallest order:");
        for (int horse : result) {
            System.out.print(horse + " ");
        }

        scanner.close();
    }
}
