#include <stdio.h>

int main(void)
{
    int len = 0, day = 0, month = 0, sum = 0, counter = 0;
    printf("Enter the number of candies: ");
    scanf("%d", &len);
    int candy[len];
    for (int i = 0; i < len; i++)
    {
        printf("Enter number on %d segment of the chocolate: ", (i + 1));
        scanf("%d", &candy[i]);
    }
    do
    {
        printf("Enter the birthday day: ");
        scanf("%d", &day);
    } while (day < 1 || day > 31);
    do
    {
        printf("Enter the birthday month: ");
        scanf("%d", &month);
    } while (month < 1 || month > 12);
    for (int i = 0; i <= len - month; i++)
    {
        sum = 0;
        for (int j = i; j < i + month; j++)
        {
            sum += candy[j];
        }
        if (sum == day)
        {
            counter++;
        }
    }
    printf("Number of valid segments: %d\n", counter);
    return 0;
}