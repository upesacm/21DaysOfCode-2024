#include<bits/stdc++.h>
using namespace std;

bool expression(string expr){
    stack<char>temp;

    for(int i=0;i<expr.size();i++){
        if(temp.empty()){
            temp.push(expr[i]);
        }
        else if((temp.top()=='{' && expr[i]=='}') || (temp.top()=='(' && expr[i]==')') || (temp.top()=='['  && expr[i]==']')){
            temp.pop();
        }
        else{
            temp.push(expr[i]);
        }
    }
    if(temp.empty()){
        return true;
    }
    return false;
}
int main(){
    string expr;
    cout<<"Enter a Expersion String: ";
    getline(cin,expr);
    if(expression(expr)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
