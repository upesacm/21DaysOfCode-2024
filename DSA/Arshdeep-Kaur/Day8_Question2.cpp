#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);
    
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    swap(q1, q2);
}

int pop() {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    int topElement = q1.front();
    q1.pop();
    return topElement;
}

int top() {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    return q1.front();
}

int main() {
    push(1);
    push(2);

    cout << top() << endl;
    cout << pop() << endl;
    cout << top() << endl;
}
