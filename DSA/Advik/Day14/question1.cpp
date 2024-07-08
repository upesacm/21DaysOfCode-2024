#include<bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& heights) {
    int moves = 0;
    int n = heights.size();
    bool changed = true;

    while (changed) {
        changed = false;
        vector<int> new_heights;

        new_heights.push_back(heights[0]);

        for (int i = 1; i < n; ++i) {
            if (heights[i] >= heights[i - 1]) {
                new_heights.push_back(heights[i]);
            } else {
                changed = true;
            }
        }

        if (changed) {
            heights = new_heights;
            n = heights.size();
            moves++;
        }
    }

    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    cout << minMoves(heights) << endl;

    return 0;
}