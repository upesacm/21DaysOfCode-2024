#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dfs(int n, const vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n + 1, false);
    stack<int> s;
    vector<int> dfsOrder;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            dfsOrder.push_back(node);

            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }

    return dfsOrder;
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

    vector<int> dfsOrder = dfs(n, edges, start);

    cout << "DFS order starting from node " << start << ":" << endl;
    for (int node : dfsOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
