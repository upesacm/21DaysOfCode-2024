#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class Stack {
private:
    stack<int> s;

public:
    void push(int x) {
        s.push(x);
    }

    int pop() {
        if (s.empty())
            throw out_of_range("Stack is empty");
        
        int topElement = s.top();
        s.pop();
        return topElement;
    }

    int top() {
        if (s.empty())
            throw out_of_range("Stack is empty");
        
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    Stack stack;

    try {
        stack.push(1);
        stack.push(2);
        cout << "Top: " << stack.top() << endl;
        cout << "Popped: " << stack.pop() << endl; 
        cout << "Top: " << stack.top() << endl; 
        stack.pop();
        stack.pop();
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl; 
    }

    return 0;
}
