#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void bfsShortestReach(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> distances(n, INT_MAX);
    queue<int> q;

    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cout << (distances[i] == INT_MAX ? -1 : distances[i]) << " ";
        }
    }
    cout << endl;
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
    bfsShortestReach(n, edges, start);

    return 0;
}
