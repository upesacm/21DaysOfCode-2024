#include<bits/stdc++.h>
using namespace std;
class Queue{
    stack<int>s1,s2;
    public:

    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"Enqueue: "<<x<<endl;
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue(){
        if(s1.empty()){
            cout<<"empty";
        }
        int x=s1.top();
        s1.pop();
        cout<<"Dequeue: "<<x<<endl;
    }
};

int main(){
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.dequeue();
    Q.dequeue();

    return 0;
}
