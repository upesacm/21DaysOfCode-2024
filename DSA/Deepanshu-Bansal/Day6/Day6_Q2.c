#include<stdio.h>
struct linklist{
    int num;
    int num1;
}link[100];
int main(){
    int n,n1,i,j;
    printf("Enter n ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&link[i].num);
    }

    printf("Enter n1 ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        printf("Enter number ");
        scanf("%d",&link[i].num1);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n1;j++){
            if(link[i].num==link[j].num1){
                printf("%d",link[i].num1);
                return 0;
            }
        }
    }
    return 0;
}
