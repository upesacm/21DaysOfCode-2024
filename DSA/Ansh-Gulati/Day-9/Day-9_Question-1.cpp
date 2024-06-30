#include <iostream>
#include <stack>
using namespace std;

struct MaxStack {
    stack<int> mainStack;
    stack<int> maxStack;
};

void push(MaxStack &stack, int value) {
    stack.mainStack.push(value);
    if (stack.maxStack.empty() || value >= stack.maxStack.top()) {
        stack.maxStack.push(value);
    }
}

void pop(MaxStack &stack) {
    if (stack.mainStack.empty()) {
        cout << "Stack is empty" << endl;
    }
    if (stack.mainStack.top() == stack.maxStack.top()) {
        stack.maxStack.pop();
    }
    stack.mainStack.pop();
}

int get_max(MaxStack &stack) {
    if (stack.maxStack.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack.maxStack.top();
}

bool is_empty(MaxStack &stack) {
    return stack.mainStack.empty();
}

int main() {
    MaxStack stack;
    push(stack, 1);
    push(stack, 2);
    cout << get_max(stack) << endl;
    pop(stack);
    cout << get_max(stack) << endl;

    return 0;
}
