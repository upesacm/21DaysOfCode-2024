#include<iostream>
#include<string>
#include<set>
using namespace std;

bool checkPalindrome(string str) {
    int start = 0, end = str.length()-1;
    while(start < end) {
        if(str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}

int distinctSubstringPalindromes(string str, int k) {
    set<string> palindromeStrings;
    for(int i = 0; i <= str.length()-k; i++) {
        string subString = str.substr(i,k);
        bool isPalindrome = checkPalindrome(subString);
        if(isPalindrome) palindromeStrings.insert(subString);
    }
    return palindromeStrings.size();
}

int main() {
    string str;
    cout << "Enter string : ";
    getline(cin,str);
    int length;
    cout << "Enter substring length : ";
    cin >> length;
    int ans = distinctSubstringPalindromes(str,length);
    cout << "No of distinct Palindromes of substring of length " << length << " = " << ans;
}
