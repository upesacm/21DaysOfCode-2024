#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int min_max_value(const string& str) {
    int n = str.size();
    vector<int> prefix_x(n + 1, 0);
    vector<int> prefix_y(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix_x[i] = prefix_x[i - 1] + (str[i - 1] == 'x' ? 1 : 0);
        prefix_y[i] = prefix_y[i - 1] + (str[i - 1] == 'y' ? 1 : 0);
    }

    vector<int> suffix_x(n + 1, 0);
    vector<int> suffix_y(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        suffix_x[i] = suffix_x[i + 1] + (str[i] == 'x' ? 1 : 0);
        suffix_y[i] = suffix_y[i + 1] + (str[i] == 'y' ? 1 : 0);
    }

    int min_cost = INT_MAX;

    for (int i = 0; i <= n; ++i) {
        int dig0 = suffix_x[i];
        int dig1 = prefix_y[i];
        min_cost = min(min_cost, max(dig0, dig1));
    }

    return min_cost;
}

int main() {
    string str;

    cin >> str;

    int result = min_max_value(str);
    cout << result << endl;

    return 0;
}
