#include <iostream>
#include <cstring>
using namespace std;

bool CheckPalindrome(const char str[], int start, int end)
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

int PalindromeSubstr(const char s[], int length) 
{
    int n = strlen(s);
    int count = 0;

    for (int i = 0; i <= n - length; i++) 
    {
        char substring[length + 1];
        strncpy(substring, s + i, length);
        substring[length] = '\0';

        if (CheckPalindrome(substring, 0, length - 1)) 
        {
            count++;
        }
    }

    return count;
}

int main() {
    char s[] = "ababa";
    int length = 3;

    int result = PalindromeSubstr(s, length);

    cout << "Number of palindromic substrings of length " << length << ": " << result << endl;

    return 0;
}
