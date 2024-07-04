#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to count distinct palindromic substrings of a specified length
int countDistinctPalindromicSubstrings(const string& s, int length) {
    unordered_set<string> palindromicSubstrings;

    for (int i = 0; i <= s.size() - length; ++i) {
        string substring = s.substr(i, length);
        if (isPalindrome(substring)) {
            palindromicSubstrings.insert(substring);
        }
    }

    return palindromicSubstrings.size();
}

int main() {
    string str;
    getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int length = str.size();

    int result = countDistinctPalindromicSubstrings(str, length);

    cout << "Number of distinct palindromic substrings of length " << length << ": " << result << endl;

    return 0;
}
