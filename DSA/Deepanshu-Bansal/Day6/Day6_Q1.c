#include<stdio.h>
struct linklist{
    int num;
}link[100];
int main(){
    int n,i,flag=0;
    int duplicate[100];
    printf("Enter n ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&link[i].num);
    }

    for(i=0;i<100;i++){
        duplicate[i]=0;
    }

    for(i=0;i<n;i++){
        if(duplicate[link[i].num]==0){
            duplicate[link[i].num]=1;
        }else{
            flag=1;
            printf("cycle");
            break;
        }
    }
    if(flag==0){
        printf("no cycle");
    }
    return 0;
}
