#include <iostream>
#include <stack>
using namespace std;
class Queue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2; 
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
public:
    void enqueue(int value) {
        stack1.push(value);
    }
    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cerr << "Queue is empty, cannot dequeue." << endl;
                exit(EXIT_FAILURE);
            }
            transferStack1ToStack2();
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cerr << "Queue is empty, no front element." << endl;
                exit(EXIT_FAILURE);
            }
            transferStack1ToStack2();
        }
        return stack2.top();
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.enqueue(6);
    q.enqueue(7);
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    return 0;
}