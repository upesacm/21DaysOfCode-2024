#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26

char* rear(char* str) 
{
    int cnt[MAX_CHAR] = 
    {0};
    int i, samecnt = 0, diffcnt = 0;

    for (i = 0; i < strlen(str); i++) 
    {
        cnt[str[i] - 'a']++;
    }

    for (i = 0; i < MAX_CHAR; i++) 
    {
        if (cnt[i] > 0) 
        {
            if (samecnt == 0) 
            {
                samecnt = cnt[i];
            } 
            else if (cnt[i] != samecnt) 
            {
                if (diffcnt == 0) 
                {
                    diffcnt = cnt[i];
                } 
                else 
                {
                    return "invalid";
                }
            }
        }
    }

    if (diffcnt == 0 || diffcnt == 1) 
    {
        return "valid";
    } 
    else 
    {
        return "invalid";
    }
}

int main() 
{
    char str[] = "aabbcc";
    printf("%s\n", rear(str));
    return 0;
}
