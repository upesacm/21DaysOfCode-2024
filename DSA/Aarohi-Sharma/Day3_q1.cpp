#include<bits/stdc++.h>
using namespace std;
int main(){
    string sen="The quick brown fox jumps over the lazy dog";
    transform(sen.begin(), sen.end(), sen.begin(), ::tolower);
    cout<<sen<<endl;
    set<char> unique;
    for(int i=0; i<sen.size(); i++){
        if (sen[i]>='a' && sen[i]<='z'){
            unique.insert(sen[i]);
        }
    }
    cout<<unique.size()<<endl;
    if(unique.size()==26){
        cout<<"complete";
    }
    else{
        cout<<"incomplete";
    }
}
