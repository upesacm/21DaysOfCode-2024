#include <bits/stdc++.h>
using namespace std;

int divideBar(vector<int> candy, int n, int day, int month)
{
    int sum = 0;
    int ways = 0;

    if (month > n)
        return 0;

    for (int i = 0; i < month; i++)
    {
        sum += candy[i];
    }
    if (sum == day)
        ways++;

    for (int i = month; i < n; i++)
    {
        sum += candy[i] - candy[i - month];
        if (sum == day)
        {
            ways++;
        }
    }
    return ways;
}

int main()
{
    vector<int> candy = {2, 2, 1, 3, 2};
    int n = candy.size();
    int day = 4;   
    int month = 2; 
        
    int ans = divideBar(candy, n, day, month);
    cout << ans;

    return 0;
}
