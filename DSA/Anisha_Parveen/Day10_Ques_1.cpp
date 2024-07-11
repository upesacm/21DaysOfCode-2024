#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int>& q) {
    if (q.empty() || q.size() == 1) {
        return;
    }
    
    int front = q.front();
    q.pop();
    
    reverseQueue(q);
    
    q.push(front);
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "Original Queue: ";
    printQueue(q);
    
    reverseQueue(q);
    
    cout << "Reversed Queue: ";
    printQueue(q);
    
    return 0;
}
