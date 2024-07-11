#include<bits/stdc++.h> 
using namespace std;

string checkPangram(string str){
unordered_set<char> letters;
    for (char ch : str) {
        if (isalpha(ch)) {
            letters.insert(tolower(ch));
        }
    }
    if (letters.size() == 26) {
        return "complete";
    } else {
        return "incomplete";
    }
}

int main(){
    cout << checkPangram("The quick brown fox jumps over the lazy dog");
    return 0;
}