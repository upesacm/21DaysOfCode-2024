#include <bits/stdc++.h>
using namespace std;

int maximumPossibleHeight(vector<int> stack1, vector<int> stack2, vector<int> stack3)
{
    int sumStack1 = accumulate(stack1.begin(), stack1.end(), 0);
    int sumStack2 = accumulate(stack2.begin(), stack2.end(), 0);
    int sumStack3 = accumulate(stack3.begin(), stack3.end(), 0);

    int i = 0, j = 0, k = 0;

    while (true)
    {
        if (i == sumStack1 || k == sumStack2 || j == sumStack3)
            return 0;
        if (sumStack1 == sumStack2 && sumStack2 == sumStack3)
            return sumStack1;
        if (sumStack1 > sumStack2 && sumStack1 > sumStack3)
        {
            sumStack1 -= stack1[i];
            i++;
        }
        else if (sumStack2 > sumStack1 && sumStack2 > sumStack3)
        {
            sumStack2 -= stack2[i];
            j++;
        }
        else
        {
            sumStack3 -= stack3[i];
            k++;
        }
    }
    return sumStack1;
}

int main()
{
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    int ans = maximumPossibleHeight(stack1, stack2, stack3);
    cout << "The maximum possible height of all the three stacks is: " << ans;
}
