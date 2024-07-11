#include <iostream>
using namespace std;

int main() {
    string s;
    int length;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the length of the substring: ";
    cin >> length;
    int n = s.size();
    int count = 0;

    for (int i=0; i<=n-length; i++) {
        string substring = s.substr(i, length);
        bool isPalindrome = true;
        for (int j=0; j<length/2; j++) {
            if (substring[j] != substring[length-1-j]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            bool isDistinct = true;
            for (int k=0; k<i; k++) {
                if (s.substr(k, length) == substring) {
                    isDistinct = false;
                    break;
                }
            }
            if (isDistinct) {
                count++;
            }
        }
    }

    cout << count << endl;
}
