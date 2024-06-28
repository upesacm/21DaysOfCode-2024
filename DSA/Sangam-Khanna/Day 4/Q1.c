#include <stdio.h>
#include <string.h>

int isp(char str[], int start, int end) 
{
    while (start < end) 
    {
        if (str[start++] != str[end--]) 
        {
            return 0;
        }
    }
    return 1;
}

int cnt(char str[], int length) 
{
    int count = 0;
    int n = strlen(str);

    for (int i = 0; i <= n - length; i++) 
    {
        if (isp(str, i, i + length - 1)) 
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    char string[] = "ababa";
    int length = 3;

    int result = cnt(string, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, result);

    return 0;
}
