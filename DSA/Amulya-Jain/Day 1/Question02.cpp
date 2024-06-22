/*
Question 2:
Given an array of integers and an integer k, determine the number of (i, j) pairs where i < j and the sum of the pair is divisible by k.

Inputs:
An array of integers.
An integer k.

Output:
The number of valid (i, j) pairs.

Example:
arr = [1, 3, 2, 6, 1, 2]
k = 3
Output: 5
*/

/*A simple brute force approach will work*/
#include <iostream>
using namespace std;

int PairDivisibility(int *arr, int size, int k)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] + arr[j]) % k == 0)
                count++;
        }
    }
    return count;
}

int main()
{
    int size_arr, k;
    cout << "Enter the size of array: -" << endl;
    cin >> size_arr;

    cout << "Enter the elements in array: -" << endl;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        cout << "Enter the " << i + 1 << " element: -" << endl;
        cin >> arr[i];
    }

    cout << "Enter the integer k: -" << endl;
    cin >> k;

    int no_of_pairs = PairDivisibility(arr, size_arr, k);
    cout << "Number of valid ways to divide the bar is: " << no_of_pairs << endl;

    return 0;
}
