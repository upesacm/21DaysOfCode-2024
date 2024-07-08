#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

string wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;  

    for (int i = 1; i <= s.length(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.length()] ? "YES" : "NO";
}

int main() {
    string s = "applepie";
    vector<string> wordDict = {"apple", "pie"};

    cout << "Output: " << wordBreak(s, wordDict) << endl; 

    return 0;
}
