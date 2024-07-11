#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int>& q) {
    // Base case: if queue is empty
    if (q.empty()) {
        return;
    }

    // Dequeue the front element
    int front = q.front();
    q.pop();

    // Reverse the remaining queue
    reverseQueue(q);

    // Enqueue the front element at the back of the queue
    q.push(front);
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
