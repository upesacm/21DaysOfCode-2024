#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &numberString, int start, int end)
{
    if (start >= end)
        return true;
    if (numberString[start] != numberString[end])
        return false;
    return isPalindrome(numberString, start + 1, end - 1);
}

bool palindrome(int number)
{
    string numberString = to_string(number);
    return isPalindrome(numberString, 0, numberString.size() - 1);
}

int main()
{

    int number;
    cout << "Enter a number: ";
    cin >> number;

    bool ans = palindrome(number);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
}
