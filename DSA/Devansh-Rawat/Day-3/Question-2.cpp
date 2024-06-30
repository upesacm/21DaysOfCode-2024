#include <bits/stdc++.h>

using namespace std;
string isSymmetrical(string sentence)
{
    int n = sentence.length();
    string reversed;
    for (char ch :sentence)
    {
        reversed.push_back(char((int)ch))
    }
    
    return "symmetrical"
}
int main()
{
    string sentence;
    cout << "Enter the sentence: ";
    cin >> sentence;
    cout << isSymmetrical(sentence) << endl;
    return 0;
}