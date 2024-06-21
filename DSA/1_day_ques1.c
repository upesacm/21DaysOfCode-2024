#include <stdio.h>

int countWays(int arr[], int size, int day, int month)
{
    int count = 0;

    for (int i = 0; i <= size - month; i++)
    {
        int sum = 0;
        for (int j = 0; j < month; j++)
        {
            sum += arr[i + j];
        }
        if (sum == day)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int month, day;
    printf("Enter the month and date of birth respectively: ");
    scanf("%d", &month);
    scanf("%d", &day);

    printf("Enter the length of candy: ");
    int size;
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the candy array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = countWays(arr, size, day, month);
    printf("Number of ways to divide the bar: %d\n", result);

    return 0;
}
