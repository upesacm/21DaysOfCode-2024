#include <bits/stdc++.h>
using namespace std;

int maxEqualHeight(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3)
{
    int height1 = accumulate(stack1.begin(), stack1.end(), 0);
    int height2 = accumulate(stack2.begin(), stack2.end(), 0);
    int height3 = accumulate(stack3.begin(), stack3.end(), 0);
    int i = 0, j = 0, k = 0;
    while (true)
    {
        if (i == stack1.size() || j == stack2.size() || k == stack3.size())
        {
            return 0;
        }
        if (height1 == height2 && height1 == height3)
        {
            return height1;
        }
        if (height1 >= height2 && height1 >= height3)
        {
            height1 = height1 - stack1[i++];
        }
        else if (height2 >= height1 && height2 >= height3)
        {
            height2 = height2 - stack2[j++];
        }
        else if (height3 >= height1 && height3 >= height2)
        {
            height3 = height3 - stack3[k++];
        }
    }
}

int main()
{
    vector<int> stack1={3, 2, 1, 1, 1};
    vector<int> stack2={4, 3, 2};
    vector<int> stack3={1, 1, 4, 1};
    int result = maxEqualHeight(stack1, stack2, stack3);
    cout << "Maximum possible height where all stacks are equal: " << result << endl;
    return 0;
}
