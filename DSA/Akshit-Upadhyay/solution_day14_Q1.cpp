#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countMoves(vector<int>& heights) {
    int moves = 0;
    bool removed;

    do {
        removed = false;
        vector<int> newHeights;

        for (size_t i = 0; i < heights.size(); ++i) {
            if (i == 0 || heights[i] >= heights[i - 1]) {
                newHeights.push_back(heights[i]);
            } else {
                removed = true;
            }
        }

        if (removed) {
            moves++;
        }

        heights = newHeights;

    } while (removed);

    return moves;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int result = countMoves(heights);
    cout << result << endl;

    return 0;
}