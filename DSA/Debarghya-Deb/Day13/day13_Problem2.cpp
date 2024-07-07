#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(vector <int> &v,int start, int end){
    //base case
    if(start > end){
        return true;
    }

   if(v[start] == v[end] ){
        start++;
        end--;
        return checkPalindrome(v,start,end);
        
    }
    
        return false;
    


    

}

int main(){
    int number;
    cout<<"Enter the number you want to check: " ;
    cin>>number;
    
    vector <int> v;
    
    while(number != 0){
        int rem = number%10;
        number = number/10;
        v.push_back(rem);
    }
    int i = 0;
    int j = v.size()-1;
   bool answer = checkPalindrome(v,i,j);
   if(answer){
    cout<<"TRUE" << endl;
   }
   else{
    cout<<"FALSE" << endl;
   }
   
    return 0;
}