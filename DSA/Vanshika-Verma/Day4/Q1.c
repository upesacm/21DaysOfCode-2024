#include <stdio.h>
#include <string.h>
int ispalin(char str[], int start, int end) 
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
int check(char str[], int len) {
    int cnt = 0;
    int n = strlen(str);

    for (int i = 0; i <= n - len; i++) 
    {
        if (ispalin(str, i, i + len - 1)) 
        {
          cnt++;
        }
    }
    return cnt;
}
int main() 
{
    char string[] = "ababa";
    int length = 3;
    int result = check(string, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, result);
    return 0;
}
