#include<stdio.h>
#include<string.h>

int sym_not(char* word);
void rev(char *word, char *rev_word, int len);
void remove_char(char *word,int len, char *rem_word);

int main(){

    char ch[100];
    printf("Enter the sentence");
    scanf("%[^\n]s", ch);
    int len = strlen(ch);

    for(int i =0;i<len;i++)
    {
        if(ch[i]>=65 && ch[i]<=90)
        {
            ch[i]= ch[i]+32;
        }
    }


    char *rem_word;
    remove_char(ch, len,rem_word);

    int z = sym_not(rem_word);

    if(z==1)
    {
        printf("\nsymmetrical");
    }
    else{
        printf("\nnot symmetrical");
    }

    return 0;
}

int sym_not(char* word) // tells if systematic or not
{
    int len = strlen(word);
    if(len%2 !=0)
    {
        return 0;
    }
    char rev_word[len];

    rev(word, rev_word,len);


    char alpha[] = "abcdefghijklmnipqrstuvwxyz";

    for(int i =0; i<len;i++){
        char ch = word[i];
        int charAt=0;

        for(int j =0;j<26;j++) //charAt in alpha 
        {
            if(ch == alpha[j])
            {
                charAt = j;
                break;
            }
        }

        printf(" \n%d", charAt);

        printf(" \n %c \t %c",alpha[25-charAt] , rev_word[i] );
        if(rev_word[i] != alpha[25-charAt]){
            return 0;
        }
    }

    return 1;
}

void rev(char *word, char *rev_word,int len)//reverse string
{

    int j = 0;
    for(int i=len-1;i>=0 ; i--)
    {
        rev_word[j] = word[i];
        j++;
    }
    rev_word[j] ='\0';

}


void remove_char(char *word,int len,char *rem_word){ //removes word
        
    int j=0;
    for(int i=0;i<len;i++){
        if(word[i]>=97 && word[i]<=122)
        {
            rem_word[j] = word[i];
            j++;
        }
    }
    rem_word[j]='\0';

}