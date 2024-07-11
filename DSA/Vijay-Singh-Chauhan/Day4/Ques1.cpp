#include <iostream>
#include <string>

using namespace std;

int countPalindromicSubstrings(string s, int length)
{
    int count = 0;

    for (int i = 0; i <= s.length() - length; i++)
    {
        string substring = s.substr(i, length);
        bool isPalindrome = true;

        for (int j = 0; j < length / 2; j++)
        {
            if (substring[j] != substring[length - 1 - j])
            {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string s = "abababd";
    int length = 3;
    int result = countPalindromicSubstrings(s, length);
    cout << result << endl; // Output: 3
    return 0;
}
