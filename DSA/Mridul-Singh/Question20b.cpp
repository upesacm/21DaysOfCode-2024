#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int vertices, vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(vertices + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int vertices = 4;
    vector<vector<pair<int, int>>> adj(vertices + 1);
    vector<tuple<int, int, int>> edges = {
        {1, 2, 4},
        {1, 3, 1},
        {2, 4, 2},
        {3, 4, 3}
    };
    int start = 1;
    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> distances = dijkstra(vertices, adj, start);
    for (int i = 1; i <= vertices; ++i) {
        cout << "Distance from node " << start << " to node " << i << " is " << distances[i] << endl;
    }
    return 0;
}
