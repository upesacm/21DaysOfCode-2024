#include <iostream>
using namespace std;

string replaceWithReverseAscii(string input) {
    int n = input.length();
    for(int i=0; i<n; i++) {
        cout << input[i] << " ";
        if (input[i] >= 'A' && input[i] <= 'Z') {
            // Reverse uppercase letters
            input[i] = 'Z' - (input[i] - 'A');
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            // Reverse lowercase letters
            input[i] = 'z' - (input[i] - 'a');
        } else {
            // Return the character unchanged if it's not a letter
            input[i] = input[i];
        } 
    }
    return input;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    string reversedAsciiValuesS = replaceWithReverseAscii(s);
    cout << reversedAsciiValuesS << endl;

    int n = s.length();
    int i=0, j=n-1;
    while (i<j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout << s << endl;

    if (s == reversedAsciiValuesS) {
        cout << "Symmetrical";
    }
    else {
        cout << "Not Symmetrical";
    }
}
