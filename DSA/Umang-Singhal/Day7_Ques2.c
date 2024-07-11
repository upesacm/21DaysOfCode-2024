#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char str[100001];
    int n,i,j;
    int left= 0, total=0;
    int min=100001;
    printf("Enter the string:");
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]=='y'){
            total++;
        }
    }
    for(i=0;i<=n;i++){
        if(i>0 && str[i-1] =='x'){
            left++;
        }
        int remove=total;
        int remaining=left;
        for(j=n-1;j>=i;j--){
            if(str[j]=='y'){
                remove--;
            }
            else{
                remaining++;
            }
            int cost = remaining>remove ? remaining:remove;
            if(cost<min){
                min= cost;
            }
        }
    }
    printf("\n%d\n",min);
    return 0;
}
