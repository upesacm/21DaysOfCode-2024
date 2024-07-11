#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(const string &numberStr, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return true;
    }
    if (numberStr[leftIndex] != numberStr[rightIndex])
    {
        return false;
    }
    return isPalindromeHelper(numberStr, leftIndex + 1, rightIndex - 1);
}

string isPalindrome(int number)
{
    string numberStr = to_string(number);

    if (isPalindromeHelper(numberStr, 0, numberStr.length() - 1))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    int testNumber;
    cout << "Enter an integer: ";
    cin >> testNumber;

    cout << isPalindrome(testNumber) << endl;

    return 0;
}
