#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<bool> visited(n + 1, false);
    stack<int> s;
    s.push(start);  
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        }
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}
int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    int start;
    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Nodes visited in DFS order from node " << start << ":" << endl;
    dfs(n, edges, start);
    cout << endl;   
    return 0;
}