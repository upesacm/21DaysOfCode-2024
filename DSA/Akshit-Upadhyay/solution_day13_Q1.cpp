#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(const string &s, const unordered_set<string> &wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int dictSize;
    cout << "Enter the size of the dictionary: ";
    cin >> dictSize;

    unordered_set<string> wordDict;
    cout << "Enter the dictionary words:" << endl;
    for (int i = 0; i < dictSize; ++i) {
        string word;
        cin >> word;
        wordDict.insert(word);
    }

    if (wordBreak(s, wordDict)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
