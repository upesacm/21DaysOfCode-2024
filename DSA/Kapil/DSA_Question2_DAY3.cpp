//here is the solution to the day 3 question 2 dsa
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string checkSymmetry(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    
    for (int i = 0; i < str.length(); i++) {
        if ((int)str[i] != (int)reversed[i]) {
            return "not symmetrical";
        }
    }
    
    return "symmetrical";
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    cout << "Result: " << checkSymmetry(input) << endl;
    
    return 0;
}
