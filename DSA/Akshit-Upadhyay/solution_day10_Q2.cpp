#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> stack1, stack2;

    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                throw out_of_range("Queue is empty");
            }
            transferStack1ToStack2();
        }
        int topVal = stack2.top();
        stack2.pop();
        return topVal;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);

    cout << "Dequeue: " << q.dequeue() << endl; 
    cout << "Dequeue: " << q.dequeue() << endl; 

    // cout << "Dequeue: " << q.dequeue() << endl; //Exception

    return 0;
}
