#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string &s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int countDistinctPalindromicSubstrings(const string &s, int k) {
    int n = s.length();
    if (k > n) return 0; // If k is greater than the length of the string, return 0

    set<string> palindromicSubstrings;

    for (int i = 0; i <= n - k; i++) {
        string substring = s.substr(i, k);

        if (isPalindrome(substring)) {
            palindromicSubstrings.insert(substring);
        }
    }

    return palindromicSubstrings.size();
}

int main() {
    string s = "abacaba"; 
    int k = 3;            
    cout << "Number of distinct palindromic substrings of length " << k << ": "
         << countDistinctPalindromicSubstrings(s, k) << endl;

    return 0;
}
