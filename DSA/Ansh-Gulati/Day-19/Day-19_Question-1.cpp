#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, int nodes, const vector<vector<int>> &adj)
{
    vector<int> distances(nodes, -1);
    queue<int> q;

    distances[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (distances[neighbor] == -1)
            {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes);

    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int start;
    cin >> start;

    vector<int> result = bfs(start - 1, nodes, adj);

    for (int i = 0; i < nodes; ++i)
    {
        if (i != start - 1)
        {
            cout << "Node " << i + 1 << ": " << result[i] << endl;
        }
    }

    return 0;
}
