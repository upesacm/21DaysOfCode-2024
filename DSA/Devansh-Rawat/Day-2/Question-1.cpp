#include <bits/stdc++.h>
using namespace std;

bool cancel(int threshold, int arrival_times[], int no_students)
{
    int no_students_ontime = 0;
    int no_students_late = 0;
    for (int i = 0; i < no_students; i++)
    {
        if (arrival_times[i] < 0)
        {
            no_students_ontime++;
            if (no_students_ontime > threshold)
                return false;
        }
        else
        {
            no_students_late++;
            if ((no_students - no_students_late) < threshold)
                return true;
        }
    }
    return false;
}

int main()
{
    int threshold;

    cout << "Enter threshold:";
    cin >> threshold;

    int arrival_times[] = {1, -3, -4, -2};

    if (cancel(threshold, arrival_times, sizeof(arrival_times) / sizeof(int)))
        cout << "YES canceled";
    else
        cout << "NO";
    return 0;
}