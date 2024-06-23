#include<stdio.h>
int main(){
    int n,i,threshold;
    printf("Enter n ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter threshold ");
    scanf("%d",&threshold);

    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&arr[i]);
    }

    int count=0;
    for(i=0;i<n;i++){
        if(arr[i]>0){
            count++;
        }
    }

    if(count>=threshold){
        printf("NO");
    }else{
        printf("YES");
    }
    return 0;
}
