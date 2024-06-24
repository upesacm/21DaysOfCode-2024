#include<stdio.h>
#include<string.h>
#include<ctype.h>

char* isPangram(char* sentence)
{
    int letters[26]={0};
    int index;
    for(int i=0;sentence[i]!='\0';i++){
        if(isalpha(sentence[i])){
            index=tolower(sentence[i])-'a';
            letters[index]=1;
        }
    }
    for(int i=0;i<26;i++){
        if(letters[i]==0){
            return "incomplete";
        }
    }
    return "complete";
}

void main()
{
    char sentence[]="The quick brown fox jumps over the lazy dog";
    printf("%s\n",isPangram(sentence));
}
