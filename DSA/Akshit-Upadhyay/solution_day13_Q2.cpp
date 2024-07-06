#include <iostream>
#include <string>

using namespace std;

bool isPalindromeHelper(const string &s, int left, int right) {
    if (left >= right) {
        return true; 
    }
    if (s[left] != s[right]) {
        return false; 
    }
    return isPalindromeHelper(s, left + 1, right - 1); 
}

string isPalindrome(int number) {
    string s = to_string(number); 
    if (isPalindromeHelper(s, 0, s.size() - 1)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << isPalindrome(number) << endl;

    return 0;
}
