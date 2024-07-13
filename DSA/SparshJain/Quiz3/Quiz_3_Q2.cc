#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    auto bfs = [&](int start, int target) -> int {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(start);
        visited[start] = true;
        int depth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                
                if (node == target) {
                    return depth;
                }
                
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            ++depth;
        }
        
        return 0;
    };

    long long result = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (A[i] == A[j]) {
                result += bfs(i, j);
            }
        }
    }

    cout << result << endl;

    return 0;
}
