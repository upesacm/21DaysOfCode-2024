import java.io.*;
import java.util.*;

public class Solution {

    static int[][] count;
    static List<Integer>[] adj;
    static int[] A;
    static int N;

    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N+1];
        int[] dist = new int[N+1];
        int value = A[start];

        queue.offer(start);
        visited[start] = true;
        dist[start] = 0;

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    queue.offer(v);

                    if (A[v] == value) {
                        count[start][v] = dist[v];
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine().trim());

        adj = new List[N+1];
        for (int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        A = new int[N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        // Initialize count array
        count = new int[N+1][N+1];

        // Perform BFS from each vertex
        for (int i = 1; i <= N; i++) {
            bfs(i);
        }

        // Calculate the result
        long result = 0;
        for (int i = 1; i <= N-1; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (A[i] == A[j]) {
                    result += count[i][j];
                }
            }
        }

        System.out.println(result);
    }
}
