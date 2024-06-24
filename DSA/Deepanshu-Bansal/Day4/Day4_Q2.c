#include<stdio.h>
#include<string.h>
int main(){
    char ch[100];
    printf("Enter string ");
    scanf("%[^\n]s",ch);

    char c[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char num[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i;

    for(i=0;i<strlen(ch);i++){
        if(c[0]==ch[i]){
            num[0]=num[0]+1;
        }else if(c[1]==ch[i]){
            num[1]=num[1]+1;
        }else if(c[2]==ch[i]){
            num[2]=num[2]+1;
        }else if(c[3]==ch[i]){
            num[3]=num[3]+1;
        }else if(c[4]==ch[i]){
            num[4]=num[4]+1;
        }else if(c[5]==ch[i]){
            num[5]=num[5]+1;
        }else if(c[6]==ch[i]){
            num[6]=num[6]+1;
        }else if(c[7]==ch[i]){
            num[7]=num[7]+1;
        }else if(c[8]==ch[i]){
            num[8]=num[8]+1;
        }else if(c[9]==ch[i]){
            num[9]=num[9]+1;
        }else if(c[10]==ch[i]){
            num[10]=num[10]+1;
        }else if(c[11]==ch[i]){
            num[11]=num[11]+1;
        }else if(c[12]==ch[i]){
            num[12]=num[12]+1;
        }else if(c[13]==ch[i]){
            num[13]=num[13]+1;
        }else if(c[14]==ch[i]){
            num[14]=num[14]+1;
        }else if(c[15]==ch[i]){
            num[15]=num[15]+1;
        }else if(c[16]==ch[i]){
            num[16]=num[16]+1;
        }else if(c[17]==ch[i]){
            num[17]=num[17]+1;
        }else if(c[18]==ch[i]){
            num[18]=num[18]+1;
        }else if(c[19]==ch[i]){
            num[19]=num[19]+1;
        }else if(c[20]==ch[i]){
            num[20]=num[20]+1;
        }else if(c[21]==ch[i]){
            num[21]=num[21]+1;
        }else if(c[22]==ch[i]){
            num[22]=num[22]+1;
        }else if(c[23]==ch[i]){
            num[23]=num[23]+1;
        }else if(c[24]==ch[i]){
            num[24]=num[24]+1;
        }else if(c[25]==ch[i]){
            num[25]=num[25]+1;
        }
    }

    int min=999999,count=0;
    for(i=0;i<26;i++){
        if(num[i]<min && num[i]!=0){
            min=num[i];
        }
    }

    for(i=0;i<26;i++){
        if(num[i]==min){
            
        }else{
            if((num[i]-1)==min && num[i]!=0){
                count++;
            }else{
                if(num[i]!=0){
                    printf("invalid");
                    break;
                }
            }
        }
    }
    if(count<=1){
        printf("valid");
    }else{
        printf("invalid");
    }
    return 0;
}
