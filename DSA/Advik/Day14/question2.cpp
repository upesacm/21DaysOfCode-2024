#include <iostream>
using namespace std;
int check(int n, int rev)
{
    if (n == 0)
    {
        return rev;
    }
    rev = (rev * 10) + (n % 10);
    check(n / 10, rev);
}
bool pall(int n)
{
    int rev = check(n, 0);
    return rev == n;
}
int main()
{
    int n;
    cin >> n;
    if (pall(n))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

#include <bits/stdc++.h>
    using namespace std;

    vector<int>
    findOrder(int n, int m, vector<pair<int, int>> &data)
    {
        vector<vector<int>> adj(n);
        vector<int> outDegree(n, 0);
        for (auto &edge : data)
        {
            adj[edge.second].push_back(edge.first);
            outDegree[edge.first]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i)
        {
            if (outDegree[i] == 0)
            {
                pq.push(i);
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            int u = pq.top();
            pq.pop();
            result.push_back(u);

            for (int v : adj[u])
            {
                outDegree[v]--;
                if (outDegree[v] == 0)
                {
                    pq.push(v);
                }
            }
        }
        return result;
    }

    int main()
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> data(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> data[i].first >> data[i].second;
        }
        vector<int> order = findOrder(n, m, data);
        for (int i : order)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }