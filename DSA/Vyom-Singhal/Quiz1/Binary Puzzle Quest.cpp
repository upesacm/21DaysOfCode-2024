#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minimumRemoval(string str) {
    int n = str.size();
    int xCount = 0, yCount = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'x') xCount++;
        else yCount++;
    }
    int result = min(xCount,yCount);
    int dig0 = xCount, dig1= 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'x') dig0--;
        else dig1++;
        int temp = max(dig0,dig1);
        result = min(result,temp);
    }
    dig0 = xCount;
    for(int i = n-1; i >= 0; i--) {
        if(str[i] == 'x') dig0--;
        else dig1++;
        int temp = max(dig0,dig1);
        result = min(result,temp);
    }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    getline(cin,str);
    int ans = minimumRemoval(str);
    cout << ans;
    return 0;
}
