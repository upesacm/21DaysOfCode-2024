#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    
    int moves = 0;
    bool removed = true;

    while (removed) {
        removed = false;
        vector<int> new_height;
        
        for (size_t i = 0; i < height.size(); i++) {
            if (i == 0 || height[i] >= height[i - 1]) {
                new_height.push_back(height[i]);
            } else {
                removed = true;
            }
        }
        
        if (removed) {
            moves++;
            height = new_height;
        }
    }
    
    cout << moves << endl;
    
    return 0;
}
