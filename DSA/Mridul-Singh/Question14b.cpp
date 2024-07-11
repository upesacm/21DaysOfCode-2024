// Geek has n horses numbered from O to n - 1 and a 2D array data of size m where data[i] = {horse_a, horse_b} denotes that horse_a is faster than horse_b.
// Geek wants to arrange the horses in order such that if horse_a is before horse_b, then horse_a is not faster than horse_b.
// Since there could be multiple arrangements, he aims to obtain the lexicographically smallest arrangement.
// Input Format
// Input: n = 4 m = 4 data = {{3, 1}, {0, 2}, {2, 1}, {0, 3}}
// Output: 1 2 3 0
// Explanation: The slowest horse is 1, and the fastest horse is O. Horses 2 and 3 have speeds between them. The order 1, 2, 3, O represents the lexicographically smallest valid order.

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, int m, vector<pair<int, int>>& data) {
    vector<vector<int>> adj(n);
    vector<int> outDegree(n, 0);
    for (auto& edge : data) {
        adj[edge.second].push_back(edge.first);
        outDegree[edge.first]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        if (outDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            outDegree[v]--;
            if (outDegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> data(m);
    for (int i = 0; i < m; ++i) {
        cin >> data[i].first >> data[i].second;
    }
    vector<int> order = findOrder(n, m, data);
    for (int i : order) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
