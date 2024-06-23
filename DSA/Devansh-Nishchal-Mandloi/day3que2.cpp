#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSymmetric(const string& str) {
    vector<char> reversedStr;
    for (auto ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            reversedStr.push_back('z' - (ch - 'a'));
        } else if (ch >= 'A' && ch <= 'Z') {
            reversedStr.push_back('Z' - (ch - 'A'));
        } else {
            reversedStr.push_back(ch);
        }
    }

    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (reversedStr[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    bool result = isSymmetric(str);
    if (result) {
        cout << "Symmetrical" << endl;
    } else {
        cout << "Not symmetrical" << endl;
    }

    return 0;
}
