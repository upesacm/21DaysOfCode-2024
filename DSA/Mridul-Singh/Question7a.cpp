#include<bits/stdc++.h>
using namespace std;

int countProperties(const vector<int>& stations, int cost) {
    int count = 0;
    int n = stations.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= cost; ++j) {
            if (find(stations.begin(), stations.end(), stations[i] - j) == stations.end()) {
                ++count;
            }
        }
        for (int j = 1; j <= cost; ++j) {
            if (find(stations.begin(), stations.end(), stations[i] + j) == stations.end()) {
                ++count;
            }
        }
    }
    return count;
}

int minCost(int n, vector<int>& station, int p) {
    sort(station.begin(), station.end());
    int left = 0, right = 1e9;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countProperties(station, mid) >= p) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    vector<int> station;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        station.push_back(temp);
    }
    int p;
    cin >> p;
    cout << minCost(n, station, p) << endl;
    return 0;
}
