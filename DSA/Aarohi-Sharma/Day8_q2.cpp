#include <iostream>
#include <queue>
using namespace std;
class Stack {
private:
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }
    int top() {
        if (!q1.empty()) {
            return q1.front();
        } else {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
    }
    bool empty() {
        return q1.empty();
    }
};
int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl; 
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; 
    stack.pop();
    cout << "Top element after another pop: " << stack.top() << endl; 
    stack.pop();
    cout << "Is stack empty: " << boolalpha << stack.empty() << endl; 
    return 0;
}
