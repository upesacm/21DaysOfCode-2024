#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionNodes(int x, int y) {
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
        }
    }
};

int computeWeight(int x, int y, const vector<int>& arr) {
    if (arr[x - 1] == 0 || arr[y - 1] == 0) {
        return abs(x * y);
    }
    return abs(x * y - (arr[x - 1] % arr[y - 1]) - (arr[y - 1] % arr[x - 1]));
}

int minimumSpanningTreeCost(int n, vector<int>& arr) {
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int weight = computeWeight(i, j, arr);
            edges.push_back({weight, {i - 1, j - 1}});
        }
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int cost = 0;
    for (auto edge : edges) {
        int weight = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;
        if (uf.find(x) != uf.find(y)) {
            uf.unionNodes(x, y);
            cost += weight;
        }
    }

    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minimumSpanningTreeCost(n, arr) << endl;
    return 0;
}
