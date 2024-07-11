#include<stdio.h>
int main(){
    int n,k,i,j,count=0;
    printf("Enter n ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter k ");
    scanf("%d",&k);

    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(i<j){
                if((arr[i]+arr[j])%k==0){
                    count++;
                }
            }
        }
    }
    printf("Total pairs is %d",count);
    return 0;
}
