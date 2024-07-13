#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int *parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

void union_set(int *parent, int rank[], int x, int y) {
    x = find(parent, x);
    y = find(parent, y);

    if (rank[x] < rank[y])
        swap(x, y);

    parent[y] = x;
    if (rank[x] == rank[y])
        rank[x]++;
}

int minimumSpanningTree(int N, vector<int> &A) {
    vector<Edge> edges;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            int weight = abs(i * j - A[i-1] % A[j-1] - A[j-1] % A[i-1]);
            edges.push_back(Edge(i, j, weight));
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    int *parent = new int[N+1];
    int *rank = new int[N+1];

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int cost = 0;
    for (Edge e : edges) {
        int x = find(parent, e.u);
        int y = find(parent, e.v);

        if (x!= y) {
            cost += e.weight;
            union_set(parent, rank, x, y);
        }
    }

    delete[] parent;
    delete[] rank;

    return cost;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << minimumSpanningTree(N, A) << endl;
    return 0;
}
