#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adjList, int start) {
    vector<int> dist(V, INT_MAX); // Initialize distances with infinity
    vector<bool> visited(V, false); // Track visited nodes
    dist[start] = 0; // Distance to the start node is 0

    for (int i = 0; i < V; ++i) {
        // Find the unvisited node with the smallest distance
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        // If the smallest distance is infinity, the remaining nodes are not connected
        if (dist[u] == INT_MAX) break;

        visited[u] = true; // Mark the node as visited

        // Update the distances to the neighbors of the selected node
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adjList(V);
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u - 1].push_back({v - 1, weight}); // Adjusting for 0-based index
        adjList[v - 1].push_back({u - 1, weight}); // If the graph is undirected
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;
    start--; // Adjust for 0-based index

    vector<int> shortest_paths = dijkstra(V, adjList, start);

    cout << "Shortest path distances from node " << start + 1 << ":" << endl;
    for (int i = 0; i < V; ++i) {
        if (shortest_paths[i] == INT_MAX) {
            cout << "Node " << i + 1 << ": " << "INF" << endl;
        } else {
            cout << "Node " << i + 1 << ": " << shortest_paths[i] << endl;
        }
    }

    return 0;
}
