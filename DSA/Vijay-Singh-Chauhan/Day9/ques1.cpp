#include<bits/stdc++.h>
using namespace std;
class Stack{
    stack<int> S;
    stack<int> maxElem;
public:
    void getmax(){
        if(S.empty()){
            cout<<"Stack is empty.";
        }
        else{
            cout<<"Max element is: "<<maxElem.top()<<endl;
        }
    }

    void push(int x){
        if(S.empty()){
            S.push(x);
            cout<<"Push Element: "<<S.top()<<endl;
            maxElem.push(x);
            return;
        }
         if(x> maxElem.top()){
            S.push(x);
            cout<<"Push Element: "<<S.top()<<endl;
            maxElem.push(x);
         }
         else{
            S.push(x);
            cout<<"Push Element: "<<S.top()<<endl;
            maxElem.push(maxElem.top());
         }
    }
    void pop(){
        if(S.empty()){
            return;
        }
        int topelem=S.top();
        S.pop();
        maxElem.pop();
        cout<<"Top most element removed "<<topelem<<endl;
    }

};
int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.getmax();
    S.pop();
    S.getmax();

    return 0;
}
