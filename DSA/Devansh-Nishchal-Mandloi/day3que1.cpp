#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

bool isPangram(const string& sentence) {
    unordered_set<char> alphabet;
    for (auto ch : sentence) {
        if (isalpha(ch)) {
            alphabet.insert(tolower(static_cast<unsigned char>(ch)));
        }
    }
    return alphabet.size() == 26;
}

int main() {
    cout << "Enter the sentence: ";
    string sentence;
    getline(cin, sentence); 

    bool result = isPangram(sentence);
    if (result) {
        cout << "complete" << endl;
    } else {
        cout << "incomplete" << endl;
    }

    return 0;
}
