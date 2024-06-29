#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

    // Moves all elements from q1 to q2 except the last one
    void moveQueue() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }

public:
    // Push element onto stack
    void push(int x) {
        q1.push(x);
    }

    // Remove the element on top of the stack and return it
    int pop() {
        if (q1.empty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }

        // Move all elements except the last one to q2
        moveQueue();
        int topElement = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    // Get the top element of the stack
    int top() {
        if (q1.empty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }

        // Move all elements except the last one to q2
        moveQueue();
        int topElement = q1.front();

        // Push the top element back to q2
        q2.push(topElement);
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);

    cout << "Top element: " << stack.top() << endl;  // Output: 2
    cout << "Popped element: " << stack.pop() << endl;  // Output: 2
    cout << "Top element: " << stack.top() << endl;  // Output: 1

    return 0;
}
