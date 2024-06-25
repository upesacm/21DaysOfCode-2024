#include<stdio.h>
int main() {
    int t, n;
    printf("Enter threshold number of students: ");
    scanf("%d", &t);
    printf("Enter number of students: ");
    scanf("%d", &n);
    int arr[n];
    int count = 0;
    printf("Enter arrival: ");
    for(int i =0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i]  <= 0){
            count++;
        }
    }
    if(count  < t) 
        printf("Yes.\n");
    else
        printf("No");
}
