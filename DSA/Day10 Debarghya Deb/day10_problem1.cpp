#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Reverse(queue <int> &q1){
    //base condition
    if(q1.empty()){
        return;
    }
    
    
    int element = q1.front();
    q1.pop();
    Reverse(q1);
    q1.push(element);

    return;


}


int main(){
    
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);


    Reverse(q1);

    //Iterating over the queue
    queue <int> q_copy = q1;
    while(!q_copy.empty()){
        cout<< q_copy.front() << endl;

        q_copy.pop();
    }
        

    return 0;
}