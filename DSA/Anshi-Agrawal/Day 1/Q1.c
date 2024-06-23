#include <stdio.h>
int main()
{
    int candy[] = {2, 2, 1, 3, 2};
    int segments, birth_month = 2, birth_day = 4;
    int count = 0, sum = 0;
    int length = sizeof(candy) / sizeof(candy[0]);
    for (int i = 0; i < 2; i++)
    {
        sum += candy[i];
    }
    if (sum == birth_day)
    {
        count++;
    }
    for (int i = birth_month; i < length; i++)
    {
        sum = sum - candy[i - birth_month] + candy[i];
        if (sum == birth_day)
        {
            count++;
        }
    }
    printf("number of valid ways: %d", count);
    return 0;
}
