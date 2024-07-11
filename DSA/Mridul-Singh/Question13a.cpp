#include<bits/stdc++.h>
using namespace std;

bool checkWord(vector<string> &dict,string str){
    if (str.empty())
        return true;

    for(int i=1;i<=str.size();i++){
        string sub=str.substr(0,i);
        if(find(dict.begin(),dict.end(),sub)!=dict.end() && checkWord(dict,str.substr(i))){
            return true;
        }
    }
    return false;
}

int main(){
    string s = "applepie";
    vector<string> dict = {"apple", "pie"};
    if (checkWord(dict,s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}