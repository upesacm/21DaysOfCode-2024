#include <iostream>
#include <vector>

using namespace std;

// Function to count distinct palindromic substrings
int countDistinctPalindromicSubstrings(const string& s, int len) {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(len + 1, 0)); // Initialize dp table

    // Initialize base case
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Preprocess the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= len && j <= i; j++) {
            if (j == 1) {
                dp[i][j] = 1;
            } else {
                if (s[i - 1] == s[i - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    // Return the total number of distinct palindromic substrings of length 'len'
    return dp[n][len];
}

int main() {
    string s = "ababa";
    int len = 3;
    cout << countDistinctPalindromicSubstrings(s, len) << endl;

    return 0;
}
