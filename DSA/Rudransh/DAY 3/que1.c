#include<stdio.h>
#include<string.h>
#include<ctype.h>

const char* sent_checker(char str[]){
	int size;
	char stack[26];
	int top=-1;
	size= strlen(str);
	for(int i = 0;i<size;i++){
		if(isalpha(str[i])){
			char ch = tolower(str[i]);
			int flag =0;
			int temp=top;
			while(temp>=0&&flag!=1){
				if(ch ==stack[temp]){
					flag=1;
				}
				temp--;
			}
			if (flag==1){
				continue;
			}
			else{
				top++;
				stack[top]=ch;
			}
		}
		else
			continue;
	}
	if (top+1==26){
		return "complete";
	}
	else{
		return "incomplete";
	}
}
void main(){
	char str[100];
	printf("Enter a sentence : ");
	fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
	const char* ans=sent_checker(str);
	printf("%s",ans);
}
