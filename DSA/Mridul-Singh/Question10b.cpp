#include <bits/stdc++.h>
using namespace std;

stack<int> s1;
stack<int> s2;

void transfer() {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}

void enqueue(int data) {
    s1.push(data);
}

void dequeue() {
    if (s2.empty()) {
        if (s1.empty()) {
            cout << "Queue is empty" << "\n";
            return;
        }
        transfer();
    }
    cout << s2.top() << " is deleted from queue" << "\n";
    s2.pop();
}

void front() {
    if (s2.empty()) {
        if (s1.empty()) {
            cout << "Queue is empty" << "\n";
            return;
        }
        transfer();
    }
    cout << "Front of queue is: " << s2.top() << "\n";
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    front();
    dequeue();
    front();
    return 0;
}
