#include<iostream>
using namespace std;

bool isPangram(string str) {
    bool alphabetPresent[26] = {false};
    for(int i = 0; i < str.length(); i++) {
        char alpha = tolower(str[i]);
        if(alpha >= 'a' && alpha <= 'z') alphabetPresent[alpha-'a'] = true;
    }
    for(int i = 0; i < 26; i++) {
        if(alphabetPresent[i] == false) return false;
    }
    return true;
}

int main() {
    string sentence;
    cout << "Enter sentence : ";
    getline(cin,sentence);
    bool ans = isPangram(sentence);
    if(ans == true) cout << "complete";
    else cout << "incomplete";
}
