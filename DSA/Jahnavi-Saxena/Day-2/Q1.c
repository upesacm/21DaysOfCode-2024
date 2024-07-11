#include<stdio.h>

const char* is_cancelled(int threshold, int arrival_times[],int n)
{
    int on_time_students=0;//count of on time students

    for(int i=0;i<n;i++)
    {
        if(arrival_times[i]<=0)
        {
            on_time_students++;
        }
    }
    if(on_time_students < threshold)
    {
        return "Yes";
    }
    else{
        return "No";
    }
}
void main(){
    int threshold,n;
    printf("Enter the threshold number: ");
    scanf("%d",&threshold);

    printf("Enter the number of students: ");
    scanf("%d",&n);

    int arrival_time[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of students: ");
        scanf("%d",&arrival_time[i]);
    }

const char* result=is_cancelled(threshold,arrival_time,n);
    printf("%s",result);
}
