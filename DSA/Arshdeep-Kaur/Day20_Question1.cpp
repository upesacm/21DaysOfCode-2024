#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& adjList, int V) {
    vector<int> color(V, -1); //-1 means uncolored, 0 and 1 are the two colors
    
    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) { // Not yet colored
            queue<int> q;
            q.push(i);
            color[i] = 0; // Color the first node with 0
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adjList[node]) {
                    if (color[neighbor] == -1) { // If the neighbor is not colored
                        color[neighbor] = 1 - color[node]; // Assign the opposite color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) { // If the neighbor has the same color
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
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<vector<int>> adjList(V);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u-1].push_back(v-1); // Adjusting for 0-based index
        adjList[v-1].push_back(u-1); // Adjusting for 0-based index
    }
    
    if (isBipartite(adjList, V)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
