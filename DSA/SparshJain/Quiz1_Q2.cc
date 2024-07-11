#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minMaxCost(string str) {
    int n = str.size();
    int totalX = count(str.begin(), str.end(), 'x');
    int totalY = n - totalX; 
    
    int left = 0, right = n - 1;
    int dig0 = 0, dig1 = 0;
    int minCost = min(totalX, totalY);
    while (left <= right) {
        if (totalX >= totalY) {
           
            if (str[left] == 'x') {
                dig0++;
                totalX--;
            } else {
                dig1++;
                totalY--;
            }
            left++;
        } else {
            
            if (str[right] == 'x') {
                dig0++;
                totalX--;
            } else {
                dig1++;
                totalY--;
            }
            right--;
        }
        
        
        minCost = min(minCost, max(dig0, dig1));
    }
    
    return minCost;
}

int main() {
    string str;
    cin >> str;
    cout << minMaxCost(str) << endl;
    return 0;
}
