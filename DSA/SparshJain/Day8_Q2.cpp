#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;
    
    void transfer(queue<int>& from, queue<int>& to) {
        while (from.size() > 1) {
            to.push(from.front());
            from.pop();
        }
    }

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) return;
        transfer(q1, q2);
        q1.pop();
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) return -1;
        transfer(q1, q2);
        int top = q1.front();
        q2.push(top);
        q1.pop();
        swap(q1, q2);
        return top;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl; // Output: 2
    stack.pop();
    cout << stack.top() << endl; // Output: 1
    stack.pop();
    cout << stack.empty() << endl; // Output: 1 (true)
    return 0;
}
