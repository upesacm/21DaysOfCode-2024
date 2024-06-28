#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostToBuyProperties(int p, vector<int>& station) {
        sort(station.begin(), station.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int pos : station) {
            for (int d = 1; d <= p; ++d) {
                minHeap.push(d);
            }
        }
        
        int minCost = 0;
        for (int i = 0; i < p; ++i) {
            minCost += minHeap.top();
            minHeap.pop();
        }
        
        return minCost;
    }
};

int main() {
    Solution sol;
    vector<int> station = {6, 8};
    int p = 5;
    cout << "Minimum cost to buy " << p << " properties: " << sol.minCostToBuyProperties(p, station) << endl;
    return 0;
}
