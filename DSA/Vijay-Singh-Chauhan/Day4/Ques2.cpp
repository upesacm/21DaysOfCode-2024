#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string isValid(const string &s)
{
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    vector<int> nonZeroFreq;
    for (int f : freq)
    {
        if (f > 0)
        {
            nonZeroFreq.push_back(f);
        }
    }

    sort(nonZeroFreq.begin(), nonZeroFreq.end());

    int n = nonZeroFreq.size();

    if (nonZeroFreq[0] == nonZeroFreq[n - 1])
    {
        return "valid";
    }

    if ((nonZeroFreq[0] == 1 && nonZeroFreq[1] == nonZeroFreq[n - 1]) ||
        (nonZeroFreq[n - 1] == nonZeroFreq[n - 2] + 1 && nonZeroFreq[n - 2] == nonZeroFreq[0]))
    {
        return "valid";
    }

    return "invalid";
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    string result = isValid(str);
    cout << "Output: " << result << endl;

    return 0;
}
