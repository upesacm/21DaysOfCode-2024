#include<bits/stdc++.h>

using namespace std;

bool compare(char a){
    vector<char> ar={'(','{','['};
    for(int i=0;i<=ar.size()-1;i++){
        if(a==ar[i]){
            return true;
        } 
    }
    return false;
}

    char opp(char top){
    if(top=='}'){
        return '{';
    }
    if(top==')'){
        return '(';
    }
    if(top==']'){
        return '[';
    }
    return 'l';
}
    
bool isValid(string s) {
        stack<char> k;
        for(int i=0;i<=s.size()-1;i++){
            if(compare(s[i])){
                k.push(s[i]);
            }
            else if(k.empty()){return false;}
            else if(opp(s[i])==k.top()){
                
                k.pop();
            }
            else{return false;}
            
        }
        if(k.empty()){
            return true;
        }
        else{return false;}


    }





int main(){
    string str="{[()]}";
    if(isValid(str)) cout<<"YES";
    else cout<<"NO";

}