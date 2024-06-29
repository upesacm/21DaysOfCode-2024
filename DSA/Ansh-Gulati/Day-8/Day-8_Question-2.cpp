#include <iostream>
#include <queue>
using namespace std;

queue<int> mainQueue, helperQueue;

void push(int x) {
    helperQueue.push(x);
    
    while (!mainQueue.empty()) {
        helperQueue.push(mainQueue.front());
        mainQueue.pop();
    }
    
    swap(mainQueue, helperQueue);
}

int pop() {
    if (mainQueue.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    int topElement = mainQueue.front();
    mainQueue.pop();
    return topElement;
}

int top() {
    if (mainQueue.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    return mainQueue.front();
}

int main() {
    push(1);
    push(2);

    cout << top() << endl;  // Output: 2
    cout << pop() << endl;  // Output: 2
    cout << top() << endl;  // Output: 1
}
