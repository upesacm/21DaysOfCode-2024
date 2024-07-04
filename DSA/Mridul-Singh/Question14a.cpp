// In a school assembly, your class students are standing in random order. Now you need to arrange them in non decreasing order of their height.
// In one move you can remove all the students who have their height less than the student in the front of them (i.e if heights are given as an array, the student removed in a move will be ith student where height[i-1] > height[i]).
// So more formally you are given an array height[] of size n and your task is to return the minimum number of moves after which heights becomes non decreasing.
// In one move you basically remove all the students who have their height less than the student in front of them thats is ith student is removed if height[i].
// Note: 0 based indexing is used.
// Input Format
// Input: n = 6 height = {5, 6, 3, 3, 7, 1}
// Output: 2
// Explanation: After the first move students at index 2 and index 5 are removed as their height is less compared to the student in front of them so now height becomes {5,6,3,7} after first move.
// After the Second move student with height 3 at index 2 is removed as at index 1 student has a height 6 so student with height 3 gets removed and hence height becomes {5,6,7}.
// Now since the height has become non decreasing so now we dont have to remove any further students .

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
