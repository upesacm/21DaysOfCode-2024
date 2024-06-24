#include <bits/stdc++.h>
using namespace std;

string isComplete(string str, int n)
{
    set<char> mySet;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
            mySet.insert(tolower(str[i]));
    }
    if (mySet.size() == 26)
        return "Complete";
    else
        return "Incomplete";
}

int main()
{
    string str = "The quick brown fox jumps over the lazy dog";
    int n = str.size();
    string ans = isComplete(str, n);
    cout << ans;
}
