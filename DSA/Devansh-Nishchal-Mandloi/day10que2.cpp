#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> stackEnqueue;
    stack<int> stackDequeue;

    void transferStacks() {
        while (!stackEnqueue.empty()) {
            stackDequeue.push(stackEnqueue.top());
            stackEnqueue.pop();
        }
    }

public:
    void enqueue(int x) {
        stackEnqueue.push(x);
    }

    int dequeue() {
        if (stackDequeue.empty()) {
            if (stackEnqueue.empty()) {
                throw out_of_range("Queue is empty");
            }
            transferStacks();
        }
        int front = stackDequeue.top();
        stackDequeue.pop();
        return front;
    }

    bool isEmpty() const {
        return stackEnqueue.empty() && stackDequeue.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);

    try {
        cout << "Dequeued: " << q.dequeue() << endl; // Output: 1
        cout << "Dequeued: " << q.dequeue() << endl; // Output: 2

        // Uncomment the following line to test dequeue from an empty queue
        // cout << "Dequeued: " << q.dequeue() << endl;
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
