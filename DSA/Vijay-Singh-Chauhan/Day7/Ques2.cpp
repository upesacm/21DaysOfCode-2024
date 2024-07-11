#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int minMaxValue(const string &str) {
    int n = str.size();
    int x_count = 0, y_count = 0;
    
    // Count the total number of 'x' and 'y' in the string
    for (char c : str) {
        if (c == 'x') x_count++;
        else y_count++;
    }
    
    int left_x_count = 0, right_y_count = y_count;
    int min_cost = max(x_count, y_count); // Initialize with the worst case
    
    // Iterate through the string to find the optimal split
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') left_x_count++;
        else right_y_count--;
        
        // Calculate max(dig0, dig1) where
        // dig0 is the number of 'x' left in the middle section
        // dig1 is the number of 'y' removed from the middle section
        int dig0 = x_count - left_x_count;  // 'x' left in the middle
        int dig1 = y_count - right_y_count; // 'y' removed
        
        min_cost = min(min_cost, max(dig0, dig1));
    }
    
    return min_cost;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     string str;
    cin >> str;
    cout << minMaxValue(str) << endl;
    return 0;
    return 0;
}
