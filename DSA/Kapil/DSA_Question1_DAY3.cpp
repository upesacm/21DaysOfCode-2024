//here is the solution for the dsa question 1 day 3
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string isPangram(string sentence) {
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    bool alphabet[26] = {false};
    for (char c : sentence) {
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = true;
        }
    }
    for (bool present : alphabet) {
        if (!present) {
            return "incomplete";
        }
    }
    return "complete";
}
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Result: " << isPangram(sentence) << endl;
    return 0;
}
