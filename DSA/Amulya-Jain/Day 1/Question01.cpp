/*
Question 1:
Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the bar into a contiguous segment
such that:
The segment length matches Raju's birth month.
The sum of the numbers in the segment equals Raju's birth day.

Inputs:
An array of integers representing the chocolate squares.
Two integers representing Raju's birth day and birth month.

Output:
The number of valid ways to divide the bar.

Example:
Candy = [2, 2, 1, 3, 2]
day = 4
month = 2
Output: 2
*/

#include <iostream>
using namespace std;

int ValidWays(int *arr, int size, int birthday, int birthmonth)
{
    int count = 0;

    for (int i = 0; i < size - birthmonth + 1; i++) // size - birthmonth + 1 tells the no of ways array can be divided contiguous segments of birthmonth length
    {
        int sum = 0;

        for (int j = i; j < i + birthmonth; j++) // [i, i+ birthmonth] tells the range from where we have to proceed to calculate our ans by adding the value at indexes in the range
        {
            sum += arr[j];
        }

        if (sum == birthday)
            count++;
    }

    return count;
}

int main()
{
    int birthday, birthmonth, size_arr;
    cout << "Enter the birthday of Raju: -" << endl;
    cin >> birthday;

    cout << "Enter the birthmonth of Raju: -" << endl;
    cin >> birthmonth;

    cout << "Enter the size of array (number of chocolate squares): -" << endl;
    cin >> size_arr;

    cout << "Enter the elements or numbers present in each chocolate square of array: -" << endl;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        cout << "Enter the " << i + 1 << " element: -" << endl;
        cin >> arr[i];
    }

    int no_of_validways = ValidWays(arr, size_arr, birthday, birthmonth);
    cout << "Number of valid ways to divide the bar is: " << no_of_validways << endl;

    return 0;
}
// It can optimized further to complexity of O(n) also.
// Some sample test cases
// // Test case 1: Example case
// int arr1[] = {1, 2, 1, 3, 2};
// int size1 = sizeof(arr1) / sizeof(arr1[0]);
// printf("Test 1 - Number of ways: %d\n", ValidWays(arr1, size1, 3, 2)); // Expected: 2

// // Test case 2: Empty array
// int arr2[] = {};
// int size2 = sizeof(arr2) / sizeof(arr2[0]);
// printf("Test 2 - Number of ways: %d\n", ValidWays(arr2, size2, 3, 2)); // Expected: 0

// // Test case 3: Birthmonth greater than array size
// int arr3[] = {1, 2};
// int size3 = sizeof(arr3) / sizeof(arr3[0]);
// printf("Test 3 - Number of ways: %d\n", ValidWays(arr3, size3, 3, 3)); // Expected: 0

// // Test case 4: Birthmonth equal to array size
// int arr4[] = {1, 2, 3};
// int size4 = sizeof(arr4) / sizeof(arr4[0]);
// printf("Test 4 - Number of ways: %d\n", ValidWays(arr4, size4, 6, 3)); // Expected: 1

// // Test case 5: Array with all elements zero
// int arr5[] = {0, 0, 0, 0, 0};
// int size5 = sizeof(arr5) / sizeof(arr5[0]);
// printf("Test 5 - Number of ways: %d\n", ValidWays(arr5, size5, 0, 2)); // Expected: 4

// // Test case 6: Single element array
// int arr6[] = {3};
// int size6 = sizeof(arr6) / sizeof(arr6[0]);
// printf("Test 6 - Number of ways: %d\n", ValidWays(arr6, size6, 3, 1)); // Expected: 1
