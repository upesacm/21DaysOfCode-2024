#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> distances(n, numeric_limits<int>::max());
    distances[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node])
            continue;

        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            int newDist = dist + edgeWeight;

            if (newDist < distances[nextNode]) {
                distances[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return distances;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter the edges (u v w format): " << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v; 
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;
    --start; 

    vector<int> shortestPaths = dijkstra(n, graph, start);

    cout << "Shortest path distances from node " << start + 1 << " are:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i + 1 << ": " << shortestPaths[i] << endl;
    }

    return 0;
}
