/*
Question 2: Create a function to check if reversing the ASCII values of a string results in the same sequence when read backward. If true, return "symmetrical", otherwise return "not symmetrical".

Inputs:
A string
Output:
"symmetrical" if the string meets the criteria, otherwise "not symmetrical".
Example:
string = "acxz"

Output: symmetrical
*/

#include <bits/stdc++.h>
using namespace std;

string checkSymmetrical(const string& str) {
    int n = str.length();
    vector<int> asciiValues(n);

    for (int i = 0; i < n; i++) {
        asciiValues[i] = int(str[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        if (asciiValues[i] != asciiValues[n - 1 - i]) {
            return "not symmetrical";
        }
    }

    return "symmetrical";
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = checkSymmetrical(input);
    cout << "Output: " << result << endl;

    return 0;
}
