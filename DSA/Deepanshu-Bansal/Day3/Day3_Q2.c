#include<stdio.h>
#include<string.h>

int function(int num){
    if(num==0){
        printf("not symmetrical");
        return 0;
    }
    printf("symmetrical");
}

int main(){
    char ch[100];
    printf("Enter string ");
    scanf("%s",ch);

    int i,j,flag=0;
    if(strlen(ch)%2!=0){
        function(0);
    }
    j=strlen(ch)-1;
    for(i=0;i<strlen(ch)/2;i++){
        flag=0;
        if((ch[i]=='a'&&ch[j]=='z') || (ch[i]=='z'&&ch[j]=='a')){
            flag=1;
            j--;
        }else if((ch[i]=='b'&&ch[j]=='y') || (ch[i]=='y'&&ch[j]=='b')){
            flag=1;
            j--;
        }else if((ch[i]=='c'&&ch[j]=='x') || (ch[i]=='x'&&ch[j]=='c')){
            flag=1;
            j--;
        }else if((ch[i]=='d'&&ch[j]=='w') || (ch[i]=='w'&&ch[j]=='d')){
            flag=1;
            j--;
        }else if((ch[i]=='e'&&ch[j]=='v') || (ch[i]=='v'&&ch[j]=='e')){
            flag=1;
            j--;
        }else if((ch[i]=='f'&&ch[j]=='u') || (ch[i]=='u'&&ch[j]=='f')){
            flag=1;
            j--;
        }else if((ch[i]=='g'&&ch[j]=='t') || (ch[i]=='t'&&ch[j]=='g')){
            flag=1;
            j--;
        }else if((ch[i]=='h'&&ch[j]=='s') || (ch[i]=='s'&&ch[j]=='h')){
            flag=1;
            j--;
        }else if((ch[i]=='i'&&ch[j]=='r') || (ch[i]=='r'&&ch[j]=='i')){
            flag=1;
            j--;
        }else if((ch[i]=='j'&&ch[j]=='q') || (ch[i]=='q'&&ch[j]=='j')){
            flag=1;
            j--;
        }else if((ch[i]=='k'&&ch[j]=='p') || (ch[i]=='p'&&ch[j]=='k')){
            flag=1;
            j--;
        }else if((ch[i]=='l'&&ch[j]=='o') || (ch[i]=='o'&&ch[j]=='l')){
            flag=1;
            j--;
        }else if((ch[i]=='m'&&ch[j]=='n') || (ch[i]=='n'&&ch[j]=='m')){
            flag=1;
            j--;
        }

        if(flag==0){
            function(0);
            break;
        }
    }
    if(flag==1){
        function(1);
    }
    return 0;
}
