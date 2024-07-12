#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int u, v, weight;
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    int n;
  
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<Edge> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int weight = abs(i * j - A[i - 1] % A[j - 1] - A[j - 1] % A[i - 1]);
            edges.push_back({i, j, weight});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    int mst_cost = 0;
    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            mst_cost += edge.weight;
            unite(parent, rank, edge.u, edge.v);
        }
    }

    cout  << mst_cost << endl;

    return 0;
}
