#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue{
public:   
    stack<int> s1;
    stack<int> s2;

    void enqueue(int value){
        this ->s1.push(value);
    }
    int dequeue(){
        
        
        while(!s1.empty()){
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }

        if(s2.empty()){
            cout<< "The stack is empty" << endl;
            return -1;
        }

        int output = s2.top();
        cout<<"The first element in the queue now is : "<< output << endl;      
        s2.pop();
    }

};


int main(){

    Queue* new_queue = new Queue();
    new_queue->enqueue(1);
    new_queue->enqueue(2);
    new_queue->enqueue(3);

    

    new_queue->dequeue();
    new_queue->dequeue();
    new_queue->dequeue();


    return 0;
}