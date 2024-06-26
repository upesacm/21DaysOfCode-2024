#include<stdio.h>
struct linklist{
    int num;
}link[100];
int main(){
    int n,i;
    printf("Enter n ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&link[i].num);
    }

    printf("Reverse linklist:\n");
    for(i=n-1;i>=0;i--){
        printf("%d ",link[i].num);
    }
    return 0;
}
