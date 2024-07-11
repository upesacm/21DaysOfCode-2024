#include<bits/stdc++.h>
using namespace std;

 bool pangram(string sentence) {
     int arr[26]={0};
        for(int i=0;i<sentence.length();i++)
        {
            arr[sentence[i]-97]++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0) return false;
        }
        return true;
}

int main(){
    string sentence;
    cout<<"Enter a Sentences: ";
    getline(cin,sentence);
    

    bool result=pangram(sentence);
    if(result==true){
        cout<<"Complete";
    }
    else{
        cout<<"Incomplete";
    }
    return 0;
}
