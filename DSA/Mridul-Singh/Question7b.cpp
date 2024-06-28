#include<bits/stdc++.h>
using namespace std;

int minMaxValue(string str) {
    int n = str.size();
    int totalX = 0, totalY = 0;
    for (char c : str) {
        if (c == 'x') {
            totalX++;
        } else if (c == 'y') {
            totalY++;
        }
    }

    int minValue = max(totalX, totalY);
    int leftX = 0, rightY = totalY;
    for (char c : str) {
        if (c == 'x') {
            leftX++;
        } else if (c == 'y') {
            rightY--;
        int currentCost = max(leftX, rightY);
        minValue = min(minValue, currentCost);
    }

    return minValue;
}

int main() {
    string str;
    cin >> str;
    cout << minMaxValue(str) << endl;
    return 0;
}
