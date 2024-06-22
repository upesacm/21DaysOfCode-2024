#include <iostream>
using namespace std;

int numberOfValidPairs(int size, int arr[], int k)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((i < j) && ((i + j) % k == 0))
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Input elements in array: ";

    // For taking input
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of 'k': ";
    cin >> k;

    int result = numberOfValidPairs(size, arr, k);
    cout << "The number of Valid pairs of i,j in the given array are: " << result;
}
