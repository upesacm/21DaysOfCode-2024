#include <bits/stdc++.h>

using namespace std;
string isPangram(string sentence)
{
    set<char> unique_alphabet;
    for (char ch : sentence)
    {
        if (isalpha(ch))
        {
            unique_alphabet.insert(tolower(ch));
        }
    }

    if (unique_alphabet.size() == 26)
    {
        return "complete";
    }
    else
    {
        return "incomplete";
    }
}
int main()
{
    string sentence;
    cout << "Enter the sentence: ";
    cin >> sentence;
    cout << isPangram(sentence) << endl;
    return 0;
}