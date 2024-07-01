#include<iostream>
#include<stack>
using namespace std;

stack<int> mainStack;
stack<int> maximumStack;

void push(int data) {
    mainStack.push(data);
    if(maximumStack.empty() || data > maximumStack.top()) maximumStack.push(data);
}

void pop() {
    if(mainStack.empty()) cout << "Underflow";
    if(mainStack.top() == maximumStack.top()) maximumStack.pop();
    mainStack.pop();
}

void getMaximumElement() {
    if(maximumStack.empty()) cout << "Underflow";
    cout << maximumStack.top() << endl;
}

int main() {
    push(2);
    push(1);
    getMaximumElement();
    pop();
    getMaximumElement();
}
