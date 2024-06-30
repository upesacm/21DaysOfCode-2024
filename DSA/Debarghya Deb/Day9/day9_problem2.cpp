#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isBalanced(string& str) {
    stack<char> s;
    unordered_map<char, char> matching_bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || s.top() != matching_bracket[ch]) {
                return false;
            }
            s.pop();
        }
    }
    
    return s.empty();
}

int main() {
    string input;
    cout<<"Enter the input : " ;
    cin>>input;


    if (isBalanced(input)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
