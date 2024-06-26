#include<stdio.h>
struct linklist{
    int num;
    int num1;
}link[100];
int main(){
    int n,n1,i,flag=1;
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

    printf("Check two linklist is identical or not:\n");
    if(n!=n1){
        printf("different");
        return 0;
    }
    for(i=0;i<n;i++){
        if(link[i].num!=link[i].num1){
            flag=0;
            printf("different");
            break;
        }
    }
    if(flag==1){
        printf("identical");
    }
    return 0;
}
