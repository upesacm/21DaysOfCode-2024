#include<bits/stdc++.h>
using namespace std;

queue <int> q1;
queue <int> q2;

void pushStack(int data){
    q2.push(data);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

void topOfStack(){
    cout << "Top of Stack is : " << q1.front() << "\n";
}

void popStack(){
    cout << q1.front() << " is poped from Stack" << "\n";
    q1.pop();
}

int main(){
    pushStack(1);
    pushStack(2);
    topOfStack();
    popStack();
    topOfStack();
    return 0;
}