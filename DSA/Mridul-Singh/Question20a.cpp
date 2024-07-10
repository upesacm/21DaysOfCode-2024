#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsCheckBipartite(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int vertices, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(vertices + 1);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<int> color(vertices + 1, -1);
    for (int i = 1; i <= vertices; ++i) {
        if (color[i] == -1) {
            if (!bfsCheckBipartite(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int vertices = 4;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};
    if (isBipartite(vertices, edges)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
