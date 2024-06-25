#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    for (int k = 3; k <= len; k++) {
        for (int i = 0; i <= len - k; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= len - n; i++) {
        if (dp[i][i + n - 1]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
