#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1; // main stack for enqueue operations
    stack<int> stack2; // auxiliary stack for dequeue operations

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (empty()) {
            cerr << "Queue is empty" << endl;
            return -1;
        }
        
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks queue;
    
    queue.enqueue(1);
    queue.enqueue(2);
    
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    
    queue.enqueue(3);
    cout << queue.dequeue() << endl;
    
    cout << queue.dequeue() << endl;
    
    return 0;
}
