#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    Stack() {
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty())
            throw out_of_range("Stack is empty");

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedValue = q1.front();
        q1.pop();

        swap(q1, q2);

        return poppedValue;
    }

    int top() {
        if (q1.empty())
            throw out_of_range("Stack is empty");

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topValue = q1.front();

        q2.push(topValue);
        q1.pop();

        swap(q1, q2);

        return topValue;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    cout << "Top: " << stack.top() << endl; 

    cout << "Popped: " << stack.pop() << endl; 
    cout << "Top: " << stack.top() << endl; 

    return 0;
}
