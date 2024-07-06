#include <bits/stdc++.h>
using namespace std;

int minBulbs(vector<int>& hallway) {
    int n = hallway.size();
    if (n == 0) return 0;
    vector<int> rightMost(n, -1);
    int bulbs = 0;
    int currentEnd = -1;
    for (int i = 0; i < n; ++i) {
        if (hallway[i] >= 0) {
            int left = max(0, i - hallway[i]);
            int right = min(n - 1, i + hallway[i]);
            rightMost[left] = max(rightMost[left], right);
        }
    }
    int i = 0;
    int farthest = 0;
    while (i < n) {
        if (i > farthest) {
            return -1;
        }
        bulbs++;
        farthest = currentEnd;
        while (i <= currentEnd && i < n) {
            if (rightMost[i] > farthest) {
                farthest = rightMost[i];
            }
            i++;
        }
        currentEnd = farthest;
    }
    return bulbs;
}

int main() {
    int n;
    cin >> n;
    vector<int> hallway(n);
    for (int i = 0; i < n; ++i) {
        cin >> hallway[i];
    }
        int result = minBulbs(hallway);
        cout << result << endl;
    return 0;
}