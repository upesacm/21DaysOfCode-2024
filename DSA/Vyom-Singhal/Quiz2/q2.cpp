#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void applyConstraints(vector<int>& order, const vector<vector<int>>& constraints) {
    bool changed;
    do {
        changed = false;
        for (const auto& constraint : constraints) {
            auto it_a = find(order.begin(), order.end(), constraint[0]);
            auto it_b = find(order.begin(), order.end(), constraint[1]);
            if (it_a > it_b) {
                iter_swap(it_a, it_b);
                changed = true;
            }
        }
    } while (changed);
}

vector<int> lexicographicallySmallestOrder(int n, int m, vector<vector<int>>& constraints) {
    vector<int> horses(n);
    for (int i = 0; i < n; ++i) {
        horses[i] = i;
    }

    applyConstraints(horses, constraints);
    return horses;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<vector<int>> constraints;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        constraints.push_back(temp);
    }
    
    vector<int> result = lexicographicallySmallestOrder(n, m, constraints);

    for (int horse : result) {
        cout << horse;
    }

    return 0;
}
