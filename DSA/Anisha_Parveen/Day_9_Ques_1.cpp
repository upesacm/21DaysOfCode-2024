#include <bits/stdc++.h>
using namespace std;

struct MaxStack {
    stack<int> mainStack;
    stack<int> maxStack;
};

void push(MaxStack& stack, int x) {
    stack.mainStack.push(x);
    if (stack.maxStack.empty() || x >= stack.maxStack.top()) {
        stack.maxStack.push(x);
    } else {
        stack.maxStack.push(stack.maxStack.top());
    }
}

void pop(MaxStack& stack) {
    if (stack.mainStack.empty()) {
        cerr << "Stack is empty" << endl;
        return;
    }
    stack.mainStack.pop();
    stack.maxStack.pop();
}

int getMax(const MaxStack& stack) {
    if (stack.maxStack.empty()) {
        cerr << "Stack is empty" << endl;
        return -1;
    }
    return stack.maxStack.top();
}

int main() {
    MaxStack stack;
    push(stack, 1);
    push(stack, 2);
    cout << getMax(stack) << endl; 
    pop(stack);
    cout << getMax(stack) << endl; 
    return 0;
}
