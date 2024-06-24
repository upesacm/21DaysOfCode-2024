#include<bits/stdc++.h> 
using namespace std;

string checkPalindrome(string str){
    int l=0;
    int r=str.size()-1;
    
    while (l<r)
    {
        int c=122-int(tolower(str[l]));
        if(97+c!=int(tolower(str[r]))){
            return "not symmetrical";
        }
        l++;
        r--;
    }
    return "symmetrical";
    
}

int main(){
    cout << checkPalindrome("dacxzw");
    return 0;
}