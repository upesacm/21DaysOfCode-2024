#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInDictionary(const string &word, const vector<string> &dictionary)
{
    for (const string &dictWord : dictionary)
    {
        if (word == dictWord)
        {
            return true;
        }
    }
    return false;
}

bool canSegmentString(const string &inputString, const vector<string> &dictionary)
{
    int stringLength = inputString.length();
    vector<bool> segmentable(stringLength + 1, false);
    segmentable[0] = true;

    for (int end = 1; end <= stringLength; ++end)
    {
        for (int start = 0; start < end; ++start)
        {
            if (segmentable[start] && isInDictionary(inputString.substr(start, end - start), dictionary))
            {
                segmentable[end] = true;
                break;
            }
        }
    }

    return segmentable[stringLength];
}

int main()
{
    string inputString;
    int dictionarySize;
    vector<string> dictionary;

    cout << "Enter the string to be segmented: ";
    cin >> inputString;

    cout << "Enter the number of words in the dictionary: ";
    cin >> dictionarySize;

    cout << "Enter the dictionary words: ";
    for (int i = 0; i < dictionarySize; ++i)
    {
        string word;
        cin >> word;
        dictionary.push_back(word);
    }

    if (canSegmentString(inputString, dictionary))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
