#include <iostream>
using namespace std;

bool classCancelledOrNot(int size, int arrival_times[], int threshold)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arrival_times[i] < 0)
        {
            count++;
        }
    }

    if (count < threshold)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arrival_times[100];

    cout << "Input the arrival times in the array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> arrival_times[i];
    }

    int threshold;
    cout << "Enter the threshold number of students : ";
    cin >> threshold;

    if (classCancelledOrNot(size, arrival_times, threshold))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
