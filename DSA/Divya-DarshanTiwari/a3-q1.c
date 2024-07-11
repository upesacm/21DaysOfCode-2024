#include<stdio.h>
#include<string.h>

int complete_or_not(char* sentence);


int main(){

    char ch[100];
    printf("Enter the sentence of maximum words including space of 100 words");
    scanf("%[^\n]s", ch);
    int len = strlen(ch);
    for(int i =0;i<len;i++)
    {
        if(ch[i]>=65 && ch[i]<=90)
        {
            ch[i]= ch[i]+32;
        }
    }

    int k = complete_or_not(ch);

    if(k == 0)
    {
        printf("incomplete");
    }
    else
    {
        printf("complete");
    }

    return 0;
}

int complete_or_not(char* sentence)
{
    char ch[] = "abcdefghijklmnopqrstuvwxyz";
    int len = strlen(sentence);
    int count[26] ={0};
    for(int i=0; i<26;i++)
    {
        char z = ch[i];
        for(int j =0;j<len;j++)
        {
            if(z== sentence[j])
            {
                count[i]++;
            }
        }
    }
    for(int i= 0; i<26; i++)
    {
        if(count[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}