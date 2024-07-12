import java.util.*;

class Edge implements Comparable<Edge> {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge other) {
        return this.weight - other.weight;
    }
}

class UnionFind {
    private int[] parent, rank;

    public UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
}

public class MinimumSpanningTree {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int[] A = new int[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        PriorityQueue<Edge> edges = new PriorityQueue<>();
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int weight = Math.abs((i + 1) * (j + 1) - (A[i] % A[j]) - (A[j] % A[i]));
                edges.add(new Edge(i, j, weight));
            }
        }
        
        UnionFind uf = new UnionFind(N);
        int mstCost = 0;
        int edgesInMST = 0;
        
        while (!edges.isEmpty() && edgesInMST < N - 1) {
            Edge edge = edges.poll();
            
            if (uf.union(edge.u, edge.v)) {
                mstCost += edge.weight;
                edgesInMST++;
            }
        }
        
        System.out.println(mstCost);
        
        scanner.close();
    }
}
