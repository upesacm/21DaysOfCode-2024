#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(const string &str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindromeHelper(str, start + 1, end - 1);
}

string isPalindrome(int number) {
    string str = to_string(number);
    
    if (isPalindromeHelper(str, 0, str.length() - 1)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int number = 121;
    cout << isPalindrome(number) << endl;

    return 0;
}
