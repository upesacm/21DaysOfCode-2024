#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int>q1,q2;

public:

void push(int x){
    q2.push(x);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}
int pop(){
    if(q1.empty()){
        return -1;
    }
    int topelem=q1.front();
    q1.pop();
    return topelem;
}

int top(){
    if(q1.empty()){
        return -1;
    }
    return q1.front();
}
bool empty(){
    return q1.empty();
}
};

int main(){
    Stack s1;

    s1.push(1);
    s1.push(2);

    cout<<"Top Element: "<<s1.top()<<endl;
    cout<<"Pop Element: "<<s1.pop()<<endl;
    cout<<"Top Element: "<<s1.top()<<endl;

    return 0;
}
