#include <bits/stdc++.h>
using namespace std;

vector<int> bfsShortestReach(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    vector<int> distances(n, -1);
    queue<int> q;
    q.push(start);
    distances[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    int start;
    cin >> start;
    start--;
    vector<int> distances = bfsShortestReach(n, edges, start);
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cout << distances[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
