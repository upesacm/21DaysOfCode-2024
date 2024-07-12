#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> bfs_distance(const unordered_map<int, vector<int>> &tree, int start) {
    unordered_map<int, int> distances;
    queue<int> q;
    q.push(start);
    distances[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int current_distance = distances[node];
        for (int neighbor : tree.at(node)) {
            if (distances.find(neighbor) == distances.end()) {
                distances[neighbor] = current_distance + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}

int calculate_f(int N, const unordered_map<int, vector<int>> &tree, const vector<int> &A) {
    int total_sum = 0;
    unordered_map<int, unordered_map<int, int>> all_distances;
    for (int i = 1; i <= N; ++i) {
        all_distances[i] = bfs_distance(tree, i);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (A[i - 1] == A[j - 1]) {
                total_sum += all_distances[i][j];
            }
        }
    }
    return total_sum;
}

int main() {
    int N;
    vector<pair<int, int>> edges;
    vector<int> A;
    cin >> N;
    edges.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    unordered_map<int, vector<int>> tree;
    for (const auto &edge : edges) {
        tree[edge.first].push_back(edge.second);
        tree[edge.second].push_back(edge.first);
    }
    int result = calculate_f(N, tree, A);
    cout << result << endl;
    return 0;
}
