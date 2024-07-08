#include <iostream>
#include <string>

using namespace std;

bool isPalindromeHelper(const string& s, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    return isPalindromeHelper(s, start + 1, end - 1);
}

string isPalindrome(int num) {
    string s = to_string(num);
    return isPalindromeHelper(s, 0, s.length() - 1) ? "YES" : "NO";
}

int main() {
    int number = 121;

    cout << "Output: " << isPalindrome(number) << endl; 

    return 0;
}
