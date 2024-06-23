#include <bits/stdc++.h>
using namespace std;

int countpairs(vector<int> arr, int k)
{
    unordered_map<int, int> remainderCount;
    for (int num : arr)
    {
        int remainder = num % k;
        remainderCount[remainder]++;
    }

    int count = 0;

    for (auto &pair : remainderCount)
    {
        int remainder = pair.first;
        int complement = (k - remainder) % k;

        if (remainder == complement)
        {
            count += pair.second / 2;
        }
        else
        {
            if (remainderCount.find(complement) != remainderCount.end())
            {
                count += std::min(pair.second, remainderCount[complement]);
            }
        }
    }
    return count;
}

int main()
{

    vector<int> arr = {1, 3, 2, 6, 1, 2};

    int k = 3;

    cout << countpairs(arr, k);
}