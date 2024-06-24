#include<stdio.h>
int main() {
    int t,n,i; 
    printf("Enter threshold number of students: \n");
    scanf("%d",&t);

    printf("Enter no. of arrival times: \n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter arrival times: \n");
    for(i=0;i<n;i++) {
        scanf("%d",&n);
    }

    int count=0;
    for(i=0;i<n;i++) {
        if(arr[i]<0) {
            count++;
        }
    }
    if (count<t) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
