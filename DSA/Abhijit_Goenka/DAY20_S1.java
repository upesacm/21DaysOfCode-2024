import java.util.*;
class DAY20_S1 
{
    public static void main(String[] args) 
    {
        int vertices = 4;
        int edges = 4;
        int[][] edgeList = 
        {
            {1, 2},
            {1, 3},
            {2, 4},
            {3, 4}
        };

        System.out.println(isBipartite(vertices, edgeList) ? "YES" : "NO");
    }

    public static boolean isBipartite(int vertices, int[][] edges) 
    {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) 
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        int[] colors = new int[vertices];
        Arrays.fill(colors, 0);

        for (int i = 0; i < vertices; i++) 
        {
            if (colors[i] == 0) {
                if (!bfsCheck(graph, i, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

    private static boolean bfsCheck(List<List<Integer>> graph, int start, int[] colors) 
    {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        colors[start] = 1; 

        while (!queue.isEmpty()) 
        {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) 
            {
                if (colors[neighbor] == 0) 
                {
                    colors[neighbor] = -colors[node];
                    queue.add(neighbor);
                } else if (colors[neighbor] == colors[node]) 
                {
                    return false;
                }
            }
        }

        return true;
    }
}
