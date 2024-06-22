#include <bits/stdc++.h>
using namespace std;

int validPairs(vector<int> arr, int n, int k)
{
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
                if ((arr[i] + arr[j]) % k == 0)
                    pairs++;
        }
    }
    return pairs;
}

int main()
{
    vector<int> arr = {1, 3, 2, 6, 1, 2};
    int n = arr.size();
    int k = 3;
    int ans = validPairs(arr, n, k);
    cout << ans;
    return 0;
}
