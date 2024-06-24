#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1="acxz";
    string s2;
    for (int i=0; i<s1.size(); i++){
        s2+=to_string(int(s1[i]));
    }
    string rev=s2;
    reverse(rev.begin(), rev.end());
    if(s2==rev){
        cout<<"symmetrical";
    }
    else{
        cout<<"not symmetrical";
    }
}
