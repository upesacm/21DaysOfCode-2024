#include<iostream>
#include<string>
#include<stack>
using namespace std;

string isBracketsBalanced(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(') s.push(str[i]);
        else if(str[i] == ']' || str[i] == '}' || str[i] == ')') {
            char top = s.top();
            s.pop();
            if(str[i] == ']' && top != '[') return "NO";
            else if(str[i] == '}' && top != '{') return "NO";
            else if(str[i] == ')' && top != '(') return "NO";
        }
    }
    if(s.empty()) return "YES";
    else return "NO";
}

int main() {
    string str;
    getline(cin,str);
    cout << isBracketsBalanced(str);
}