#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int minBulbsToLightHallway(int n, vector<int>& hallway) {
    int count = 0;
    int i = 0;
    while (i < n) {
        int maxReach = -1;
        int nextBulb = -1;
        for (int j = 0; j < n; ++j) {
            if (hallway[j] != -1 && j - hallway[j] <= i && j + hallway[j] > maxReach) {
                maxReach = j + hallway[j];
                nextBulb = j;
            }
        }
        if (nextBulb == -1) return -1;
        count++;
        i = maxReach + 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> hallway;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        hallway.push_back(num);
    }
    int result = minBulbsToLightHallway(n, hallway);
    cout << result;
    return 0;
}
