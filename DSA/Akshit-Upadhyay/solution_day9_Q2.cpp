#include <iostream>
#include <stack>
#include <string>

using namespace std;

string isBalanced(const string& s) {
    stack<char> bracketStack;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);
        } else {
            if (bracketStack.empty()) return "NO";

            char top = bracketStack.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                bracketStack.pop();
            } else {
                return "NO";
            }
        }
    }

    return bracketStack.empty() ? "YES" : "NO";
}

int main() {
    
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    cout << isBalanced(s) << endl;

    return 0;
}
