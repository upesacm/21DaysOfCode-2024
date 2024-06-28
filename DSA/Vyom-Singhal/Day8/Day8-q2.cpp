#include<iostream>
#include<queue>
using namespace std;

queue<int> q1, q2;

bool isEmpty() {
    return q1.empty();
}

bool isFull(int capacity) {
    return q1.size() == capacity;
}

void push(int data) {
    if(isFull(5)) {
        cout << "Overflow";
        return;
    }
    q2.push(data);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

void top() {
    cout << q1.front();
}

void pop() {
    if(isEmpty()) {
        cout << "Underflow!";
        return;
    }
    q1.pop();
}

int main() {
    push(1);
    push(2);
    push(3);
    top();
    cout << endl;
    pop();
    top();
}