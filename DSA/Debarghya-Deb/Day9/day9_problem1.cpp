#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MaxStack {
private:
    stack<int> mainStack;
    stack<int> maxStack;

public:
    
    void push(int value) {
        mainStack.push(value);
        if (maxStack.empty() || value >= maxStack.top()) {
            maxStack.push(value);
        }
    }

    
    void pop() {
        if (mainStack.empty()) {
            return;
        }
        int value = mainStack.top();
        mainStack.pop();
        if (value == maxStack.top()) {
            maxStack.pop();
        }
    }

    
    int get_max() const {
        if (maxStack.empty()) {
            return -1;
        }
        return maxStack.top();
    }
};

int main() {
    MaxStack stack;

    
    stack.push(1);
    stack.push(2);
    cout << stack.get_max() << endl; 
    stack.pop();
    cout << stack.get_max() << endl;

    return 0;
}
