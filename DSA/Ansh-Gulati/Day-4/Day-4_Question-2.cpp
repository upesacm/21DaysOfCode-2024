#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n = s.size();
    int freq[26] = {0};

    // Count the frequency of each character
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    // Array to count the frequency of frequencies
    int freqCount[1000] = {0};
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > 0)
        {
            freqCount[freq[i]]++;
        }
    }

    // Determine the number of different frequencies
    int distinctFreqs = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (freqCount[i] > 0)
        {
            distinctFreqs++;
        }
    }

    // If there's only one frequency or all frequencies are the same, it's valid
    if (distinctFreqs == 1)
    {
        cout << "Valid" << endl;
        return 0;
    }

    // If there are more than 2 different frequencies, it's invalid
    if (distinctFreqs > 2)
    {
        cout << "Invalid" << endl;
        return 0;
    }

    // If there are exactly 2 different frequencies
    int freq1 = 0, count1 = 0, freq2 = 0, count2 = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (freqCount[i] > 0)
        {
            if (freq1 == 0)
            {
                freq1 = i;
                count1 = freqCount[i];
            }
            else
            {
                freq2 = i;
                count2 = freqCount[i];
            }
        }
    }

    // Check the conditions for validity
    // One frequency should appear exactly once and either be 1 or differ by 1 from the other frequency
    if ((count1 == 1 && (freq1 == 1 || freq1 - freq2 == 1)) || (count2 == 1 && (freq2 == 1 || freq2 - freq1 == 1)))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}
