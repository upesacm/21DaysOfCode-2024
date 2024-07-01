#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int min_cost(string str) {
    int n = str.size();
    vector<int> x_count(n + 1, 0), y_count(n + 1, 0);
    for (int i = 0; i < n; i++) {
        x_count[i + 1] = x_count[i] + (str[i] == 'x');
        y_count[i + 1] = y_count[i] + (str[i] == 'y');
    }
    int res = n;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int dig0 = x_count[j] - x_count[i];
            int dig1 = y_count[n] - y_count[j] + y_count[i];
            res = min(res, max(dig0, dig1));
        }
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    cin >> str;
    cout << min_cost(str) << endl;
    return 0;
}
