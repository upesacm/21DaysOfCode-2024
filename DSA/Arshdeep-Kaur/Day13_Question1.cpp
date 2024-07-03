#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInDictionary(const string &word, const vector<string> &dictionary) {
    for (const string &dictWord : dictionary) {
        if (word == dictWord) {
            return true;
        }
    }
    return false;
}

bool canSegmentString(const string &s, const vector<string> &dictionary) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && isInDictionary(s.substr(j, i - j), dictionary)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "applepie";
    vector<string> dictionary = {"apple", "pie"};

    if (canSegmentString(s, dictionary)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
