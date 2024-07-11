#include <iostream>
using namespace std;

int reverseNum(int n, int rev = 0) {
    if (n == 0) return rev;
    rev = rev * 10 + n % 10;
    return reverseNum(n / 10, rev);
}

string isPalindrome(int n) {
    int rev = reverseNum(n);
    if(n == rev) return "YES";
    return "NO";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << isPalindrome(n);
}