#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfs(int start, int nodes, const vector<vector<int>>& adj) {
    vector<bool> visited(nodes, false);
    vector<int> result;
    dfsUtil(start, adj, visited, result);
    return result;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1); // Assuming nodes are 1-indexed
        adj[v - 1].push_back(u - 1); // Since the graph is undirected
    }

    int start;
    cin >> start;

    vector<int> result = dfs(start - 1, nodes, adj); // Assuming nodes are 1-indexed

    for (int node : result) {
        cout << "Node " << node + 1 << " ";
    }
    cout << endl;

    return 0;
}
