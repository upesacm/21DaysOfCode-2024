#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
typedef pair<int, int> PII;
void dijkstra(int start, vector<vector<PII>>& graph, int V) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});  
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    int V, E, start;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<PII>> graph(V);
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});  
    }
    cout << "Enter the starting node: ";
    cin >> start;
    dijkstra(start, graph, V);
    return 0;
}