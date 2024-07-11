#include <bits/stdc++.h>
using namespace std;

void classCancelled(vector<int> arrivalTimes, int threshold)
{
    int count = 0;
    for (int i = 0; i < arrivalTimes.size(); i++)
    {
        if (arrivalTimes[i] <= 0)
            count++;
    }
    if (count < threshold)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    vector<int> arrivalTimes = {-1, -3, 4, 2};
    int threshold = 3;
    
    classCancelled(arrivalTimes, threshold);
}
