#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char ch[100];
    printf("Enter string: ");
    scanf("%[^\n]s", ch);

    int count[26] = {0}; // initialize all counts to 0

    for(int i = 0; i < strlen(ch); i++){
        char c = tolower(ch[i]); // convert to lowercase
        if(c >= 'a' && c <= 'z'){ // check if it's a letter
            count[c - 'a']++; // increment the corresponding count
        }
    }

    int min = 999999;
    for(int i = 0; i < 26; i++){
        if(count[i]!= 0 && count[i] < min){
            min = count[i];
        }
    }

    int diff_count = 0;
    for(int i = 0; i < 26; i++){
        if(count[i]!= 0 && count[i]!= min){
            if(count[i] - 1 == min){
                diff_count++;
            } else {
                printf("invalid\n");
                return 0;
            }
        }
    }

    if(diff_count <= 1){
        printf("valid\n");
    } else {
        printf("invalid\n");
    }

    return 0;
}