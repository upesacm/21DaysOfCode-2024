#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
}

vector<int> performDFS(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    for (auto& neighbors : graph) {
        sort(neighbors.begin(), neighbors.end());
    }
    vector<bool> visited(n, false);
    vector<int> result;
    dfs(start, graph, visited, result);
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    int start;
    cin >> start;
    start--;
    vector<int> dfsOrder = performDFS(n, edges, start);
    for (int node : dfsOrder) {
        cout << node + 1 << " ";
    }
    cout << endl;
    return 0;
}
