#include<stdio.h>
#include<stdlib.h>

int cancle_NOt(int arr[], int threshold, int no_of_students);

int main(){

    int threshold, no_of_students;

    printf("Enter the total no of students that came to class \n");
    scanf("%d", &no_of_students);

    printf("Enter the Threshold of the Class to know if to cancel or not \n");
    scanf("%d", &threshold);

    int *arr = (int*) calloc (no_of_students,sizeof(int));

    printf("Enter the arrival time in integers where a non-positive integer indicates ontime arrival\n");

    for ( int i = 0; i < no_of_students; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x = cancle_NOt(arr,threshold,no_of_students);    

    if(x == 1)
    {
        printf("NO");
    }
    else{
        printf("Yes");
    }

    return 0;
}


int cancle_NOt(int arr[], int threshold, int no_of_students)
{
    int count=0;
    if(no_of_students<threshold)
    {
        return 0;
    }
    else{
        for(int i=0;i<no_of_students; i++)
        {
            if(arr[0]>1)
            {
                count++;
                if(count>threshold)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    
}