/*
Question 1: A professor has a class of students and wants to know if the class should be cancelled based on student arrival times. 
The class is cancelled if fewer than a threshold number of students arrive on time.

Inputs:
An integer representing the threshold number of students.
An array of integers representing arrival times, where a non-positive integer indicates on-time arrival. Output:
YES" if the class is cancelled, "NO" otherwise.

Example:
threshold = 3
arrival_times = [-1, -3, 4, 2]

Output: YES
*/
// A simple linear search will be most optimised to solve this question in O(n) time.
#include  <iostream>
using namespace std;

string is_class_cancelled (int threshold_num, int *arr, int size)
{
    int present_count  = 0;
    for (int i = 0 ; i< size; i++)
    {
        if (arr[i] < 0)
        {
            present_count ++;
        }
    }
    if (present_count < threshold_num)
        return "YES";
    return "NO";
}

int main()
{
    cout << "Enter the number of threshold students: -" << endl;
    int threshold_num ;
    cin >> threshold_num;

    cout << "Enter the total number of arrival times of students: -" << endl;
    int size_arr;
    cin >> size_arr;

    cout << "Enter the arrival times of student: -" << endl;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        cout << "Enter the arrival time of " << i+1 << " student: ";
        cin >> arr[i];
    }

    cout << endl << "Class is cancelled: " << is_class_cancelled(threshold_num, arr, size_arr) << endl;

    return 0;
}
