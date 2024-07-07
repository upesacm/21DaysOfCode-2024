#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="applepie";
    string dic[]={"apple", "pie"};
    int size=sizeof(dic)/sizeof(dic[0]);
    for(int i=0; i<size; i++){
        int len=dic[i].length();
        for(int j=0; j<s.size()-len; j++){
            if(dic[i]==s.substr(j, len)){
                cout<<"yes";
            }
        }
    }
}