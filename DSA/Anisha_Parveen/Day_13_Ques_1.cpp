#include <bits/stdc++.h>
using namespace std;

bool canSegmentString(string str, vector<string> dictionary)
{
    // Convert dictionary to a set for O(1) average-time complexity lookups
    unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());

    int n = str.size();
    vector<bool> dp(n + 1, false); // dp[i] will be true if str[0...i-1] can be segmented

    dp[0] = true; // Base case: Empty string is always segmentable

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // Check if dp[j] is true (prefix str[0...j-1] can be segmented)
            // and if str[j...i-1] (substring from j to i-1) is in dictionarySet
            if (dp[j] == true && dictionarySet.find(str.substr(j, i - j)) != dictionarySet.end())
            {
                dp[i] = true; // Mark dp[i] as true if valid segmentation is found
                break;        // Exit the inner loop early as we've found a valid segmentation
            }
        }
    }

    return dp[n]; // Return whether the entire string can be segmented
}

int main()
{
    string str = "applepie";
    vector<string> dictionary = {"apple", "pie"};

    bool ans = canSegmentString(str, dictionary);

    if (ans)
        cout << "YES"; 
    else
        cout << "NO"; 

    return 0;
}
