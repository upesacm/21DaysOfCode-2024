#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minimumMoves(vector<int>& height) {
    int moves = 0;
    int n = height.size();
    while (true) {
        bool removed = false;
        vector<int> newHeight;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || height[i] >= height[i-1]) {
                newHeight.push_back(height[i]);
            } else {
                removed = true;
            }
        }
        if (!removed) {
            break;
        }
        height = newHeight;
        n = height.size();
        moves++;
    }
    return moves;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> height;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        height.push_back(num);
    }
    cout << minimumMoves(height);
    return 0;
}
