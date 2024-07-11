#include <stdio.h>

int main(){
    int thresh, num, ontime=0;
    int arr_time[10]; //we are assuming max number of students to be 10

    //input
    printf("enter the threshold: ");
    scanf("%d", &thresh);

    printf("Enter the number of students: ");
    scanf("%d", &num);

    printf("enter the arrival times of students: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr_time[i]);
    }

    //main logic
    for (int i = 0; i < num; i++)
    {
        if (arr_time[i]<0)
            ontime++;
    }

    //output
    printf("is class canceled?: ");
    if(ontime<thresh)
        printf("YES");
    else
        printf("NO");

    return 0;
}