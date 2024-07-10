#include <iostream>
#include <vector>
using namespace std;

// Function to perform BFS and find the shortest reach
vector<int> bfs(int n, const vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> distance(n + 1, -1);
    vector<int> queue(n + 1);
    int front = 0, back = 0;

    distance[start] = 0;
    queue[back++] = start;

    while (front < back) {
        int node = queue[front++];
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) { // Unvisited
                distance[neighbor] = distance[node] + 1;
                queue[back++] = neighbor;
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = bfs(n, edges, start);

    cout << "Shortest reach to each node from node " << start << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        if (i == start) {
            continue; // Skip the starting node itself
        }
        if (distances[i] == -1) {
            cout << i << ": -1 (unreachable)" << endl;
        } else {
            cout << i << ": " << distances[i] << " edges" << endl;
        }
    }

    return 0;
}
