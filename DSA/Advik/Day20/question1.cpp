#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1);  
    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {  
            queue<int> q;
            q.push(i);
            color[i] = 0;  
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {  
                        color[v] = 1 - color[u];  
                        q.push(v);
                    } else if (color[v] == color[u]) {  
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
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E; 
    vector<vector<int>> graph(V);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (isBipartite(graph, V)) {
        cout << "YES" << endl;
    } 
    else {
        cout << "NO" << endl;
    }    
    return 0;
}