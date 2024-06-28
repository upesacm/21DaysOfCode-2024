nclude <stdio.h>

// Function to count the number of valid (i, j) pairs
int countDivisiblePairs(int arr[], int n, int k)
{
    // Array to store count of remainders
    int remainder_count[k];

    // Initialize remainder counts to zero
    for (int i = 0; i < k; i++)
    {
        remainder_count[i] = 0;
    }

    // Count occurrences of each remainder
    for (int i = 0; i < n; i++)
    {
        int remainder = arr[i] % k;
        remainder_count[remainder]++;
    }

    // Initialize count of valid pairs
    int count = 0;

    // Case when remainder is 0
    count += (remainder_count[0] * (remainder_count[0] - 1)) / 2;

    // Case for all pairs (i, j) where i < j and their sum % k == 0
    for (int i = 1; i <= k / 2; i++)
    {
        if (i != k - i)
        {
            count += remainder_count[i] * remainder_count[k - i];
        }
    }

    // Case when remainder is exactly half of k (only if k is even)
    if (k % 2 == 0)
    {
        count += (remainder_count[k / 2] * (remainder_count[k / 2] - 1)) / 2;
    }

    return count;
}

int main()
{
    // Example usage
    int arr[] = {1, 3, 2, 6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = countDivisiblePairs(arr, n, k);
    printf("Number of valid (i, j) pairs: %d\n", result); // Output should be 5

    return 0;
}
