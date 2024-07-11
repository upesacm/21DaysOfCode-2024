#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1); 

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {  
            queue<int> q;
            q.push(i);
            color[i] = 0; 

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {  
                        color[neighbor] = 1 - color[node];  
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {  
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v format): " << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; 
        --v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
