#include <stdio.h>

int main(void)
{
    int len, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &len);
    int arr[len];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the integer k: ");
    scanf("%d", &k);
    int remainder_count[k];
    for (int i = 0; i < k; i++)
    {
        remainder_count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        int remainder = arr[i] % k;
        remainder_count[remainder]++;
    }
    int counter = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < k; j++)
        {
            if ((i + j) % k == 0)
            {
                if (i == j)
                {
                    counter += (remainder_count[i] * (remainder_count[i] - 1)) / 2;
                }
                else
                {
                    counter += remainder_count[i] * remainder_count[j];
                }
            }
        }
    }
    printf("Number of valid pairs: %d\n", counter);
    return 0;
}