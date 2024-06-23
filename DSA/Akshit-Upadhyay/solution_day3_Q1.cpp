#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

string isPangram(const string& sentence) {
    unordered_set<char> letters;
    
    for (char c : sentence) {
        if (isalpha(c)) {
            letters.insert(tolower(c));
        }
    }
    
    if (letters.size() == 26) {
        return "complete";
    } else {
        return "incomplete";
    }
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    cout << isPangram(sentence) << endl;

    return 0;
}
