#include <iostream>
#include <stack>
#include <string>

std::string isBalanced(const std::string& s) {
    std::stack<char> stack;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else {
            if (stack.empty()) {
                return "NO";
            }
            char top = stack.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                stack.pop();
            } else {
                return "NO";
            }
        }
    }
    return stack.empty() ? "YES" : "NO";
}

int main() {
    std::string s = "{[()]}";
    std::cout << isBalanced(s) << std::endl; // Output: YES

    s = "{[(])}";
    std::cout << isBalanced(s) << std::endl; // Output: NO

    return 0;
}
