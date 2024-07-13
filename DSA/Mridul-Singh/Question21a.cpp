#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

int find(vector<int> &parent, int u) {
    if (u != parent[u])
        parent[u] = find(parent, parent[u]);
    return parent[u];
}

bool unionSets(vector<int> &parent, vector<int> &rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU == rootV)
        return false;
    if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
    return true;
}

int calculateWeight(int x, int y, const vector<int> &A) {
    return abs(x * y - A[x-1] % A[y-1] - A[y-1] % A[x-1]);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<Edge> edges;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int weight = calculateWeight(i, j, A);
            edges.push_back({i-1, j-1, weight});
        }
    }
    sort(edges.begin(), edges.end());
    vector<int> parent(N), rank(N, 1);
    for (int i = 0; i < N; ++i)
        parent[i] = i;
    int mst_cost = 0;
    int edges_used = 0;
    for (const auto &edge : edges) {
        if (unionSets(parent, rank, edge.u, edge.v)) {
            mst_cost += edge.weight;
            edges_used++;
            if (edges_used == N - 1)
                break;
        }
    }
    cout << mst_cost << endl;
    return 0;
}