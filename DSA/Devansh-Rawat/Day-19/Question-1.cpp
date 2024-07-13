#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<int> bfs(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<int> distance(n + 1, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }   
    return distance;
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
    vector<int> result = bfs(n, edges, start);   
    cout << "Shortest reach from node " << start << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        if (i != start) {
            cout << "Node " << i << ": " << result[i] << endl;
        }
    }    
    return 0;
}