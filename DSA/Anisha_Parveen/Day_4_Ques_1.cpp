#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int isValid(string str, int len)
{
    unordered_set<string> palindromeSet;

    for (int i = 0; i <= str.size() - len; i++)
    {
        string substr = str.substr(i, len);
        if (isPalindrome(substr, 0, len - 1))
        {
            palindromeSet.insert(substr);
        }
    }

    return palindromeSet.size();
}

int main()
{
    string str = "ababa";
    int len = 3;

    int ans = isValid(str, len);
    cout << ans << endl;

    return 0;
}
