#include <bits/stdc++.h>
using namespace std;

string isValid(string str)
{
    unordered_map<char, int> charFreq;

    for (char ch : str)
        charFreq[ch]++;

    vector<int> freq;
    for (auto i : charFreq)
        freq.push_back(i.second);

    sort(freq.begin(), freq.end());

    int n = freq.size();

    if (freq[0] == freq[n - 1])
        return "valid";

    if (freq[0] == 1 && freq[1] == freq[n - 1])
        return "valid";

    if (freq[0] == freq[n - 2] && freq[n - 1] == freq[n - 2] + 1)
        return "valid";

    return "invalid";
}

int main()
{
    string str = "aabbbcc";

    string ans = isValid(str);
    cout << ans << endl;

    return 0;
}
