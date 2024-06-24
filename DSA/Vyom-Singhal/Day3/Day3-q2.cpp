#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isSymmetrical(string str) {
    if(str.length() % 2 != 0) return false;
    string reverseAsciistr = str;
    for(int i = 0; i < str.length(); i++) {
        if(reverseAsciistr[i] >= 'a' && reverseAsciistr[i] <= 'z') reverseAsciistr[i] = 'z' - (reverseAsciistr[i]-'a');
        else if(reverseAsciistr[i] >= 'A' && reverseAsciistr[i] <= 'Z') reverseAsciistr[i] = 'Z' - (reverseAsciistr[i]-'A');
    }
    reverse(reverseAsciistr.begin(),reverseAsciistr.end());
    if(reverseAsciistr == str) return true;
    else return false;
}

int main() {
    string str;
    cout << "Enter string : ";
    getline(cin, str);
    bool ans = isSymmetrical(str);
    if(ans == true) cout << "Symmetrical";
    else cout << "Not Symmetrical";
}