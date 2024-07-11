#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void dfsRecursive(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, graph, visited, result);
        }
    }
}

vector<int> dfs(int n, const vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n, false);
    vector<int> result;

    dfsRecursive(start, graph, visited, result);

    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges (u v format): " << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first; 
        --edges[i].second; 
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;
    --start; 
    vector<int> dfsOrder = dfs(n, edges, start);

    cout << "DFS Order: ";
    for (int node : dfsOrder) {
        cout << node + 1 << " "; 
    }
    cout << endl;

    return 0;
}
