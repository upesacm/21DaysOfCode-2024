#include <iostream>
#include <vector>
using namespace std;

int minMovesToNonDecreasingOrder(vector<int> &height)
{
    int n = height.size();
    int moves = 0;

    while (true)
    {
        bool removed = false;
        vector<int> newHeights;
        newHeights.push_back(height[0]);

        for (int i = 1; i < n; ++i)
        {
            if (height[i] >= height[i - 1])
            {
                newHeights.push_back(height[i]);
            }
            else
            {
                removed = true;
            }
        }

        if (!removed)
            break;

        height = newHeights;
        n = height.size();
        ++moves;
    }

    return moves;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> height[i];
    }

    cout <<  minMovesToNonDecreasingOrder(height) << endl;

    return 0;
}
