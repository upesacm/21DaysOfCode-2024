#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int>& q) {
    if(q.empty()) return;
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    printQueue(q);
    cout << endl;
    reverseQueue(q);
    printQueue(q);
}
