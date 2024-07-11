#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;
bool isBalanced(string s) {
    stack<char> charStack;
    unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (brackets.find(c) == brackets.end()) {
            charStack.push(c);
        } else {
            if (charStack.empty() || charStack.top() != brackets[c]) {
                return false;
            }
            charStack.pop();
        }
    }
    return charStack.empty();
}
int main() {
    string input = "{[()]}";
    if (isBalanced(input)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
