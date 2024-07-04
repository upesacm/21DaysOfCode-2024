#include<iostream>
using namespace std;
int ispalindrome(int num,int temp){
    if(num==0){
        return temp;
    }
    temp=(temp*10) +(num%10);
    ispalindrome(num/10,temp);
}
int main(){
    int num;
    cout<<"Enter a number whether it is palindrome or not: ";
    cin>>num;

    int temp=ispalindrome(num,0);
    if(temp==num){
        cout<<"Yes, it is palindrome";
    }
    else{
        cout<<"No, it is not palindrome";
    }

    return 0;
}
