#include <bits/stdc++.h>
using namespace std;

string isSymmetrical(string str)
{
    vector<int> asciiValues;

    for (char c : str)
    {
        asciiValues.push_back(static_cast<int>(c));
    }

    vector<int> reversed = asciiValues;
    reverse(reversed.begin(), reversed.end());

    int n = asciiValues.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (asciiValues[i] != reversed[n - 1 - i])
        {
            return "not symmetrical";
        }
    }

    return "symmetrical";
}

int main()
{
    string str = "abyz";

    string ans = isSymmetrical(str);
    cout << ans << endl;

    return 0;
}
