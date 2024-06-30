#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    
    void push(int value) {
        q1.push(value);
    }

    
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }

        
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int value = q1.front();
        q1.pop();

        
        swap(q1, q2);

        return value;
    }

    
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int value = q1.front();
        q2.push(value);
        q1.pop();

        swap(q1, q2);

        return value;
    }

    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; 
    cout << "Popped element: " << s.pop() << endl; 
    cout << "Popped element: " << s.pop() << endl; 
    cout << "Top element: " << s.top() << endl; 

    s.push(40);
    cout << "Top element: " << s.top() << endl; 
    cout << "Popped element: " << s.pop() << endl; 
    cout << "Popped element: " << s.pop() << endl; 

    return 0;
}
