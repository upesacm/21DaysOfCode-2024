#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& adj, int V) {
    vector<int> color(V, -1);  // -1 means no color is assigned yet

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {  // If the vertex is not colored
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Assign the first color

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {  // If the adjacent vertex is not colored
                        color[v] = 1 - color[u];  // Assign alternate color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // If the adjacent vertex has the same color, the graph is not bipartite
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (isBipartite(adj, V)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
