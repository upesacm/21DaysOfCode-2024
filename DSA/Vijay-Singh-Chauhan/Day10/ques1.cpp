#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<int>Queue){
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
}

void reverseQueue(queue<int>& Queue){
     if(Queue.empty()){
        return;
     }
     int data=Queue.front();
     Queue.pop();
     reverseQueue(Queue);
     Queue.push(data);
}

int main(){
    queue<int>Queue;
    int size,n;
    cout<<"Enter Size of queue: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>n;
        Queue.push(n);
    }

    cout<<"Original Queue:";
    printQueue(Queue);
    
    reverseQueue(Queue);
    cout<<endl<<"Reversed Queue: ";
    printQueue(Queue);
}
