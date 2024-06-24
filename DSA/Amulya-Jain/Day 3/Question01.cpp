#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string isSentence_complete(const string& sentence) 
{
    bool alphabet[26] = {false};
    for (char ch : sentence)
    {
        if (isalpha(ch)) 
        {
            ch = tolower(ch);
            alphabet[ch - 'a'] = true;
        }
    }
    for (bool found : alphabet) 
    {
        if (!found) 
        {
            return "incomplete";
        }
    }
    return "complete";
}

int main() 
{
    string sentence = "The quick brown fox jumps over the lazy dog";
    cout << isSentence_complete(sentence) << endl;
    return 0;
}
