#include<iostream>
using namespace std;

long long sumdigits(int num){
    int ans=0;
    if(num==0){
        return 0;
    }

    return (num%10)+sumdigits(num/10);
}
int singledigit(int num){
    if(num<10){
        return num;
    }
    else{
         singledigit(sumdigits(num));
    }
}
int main(){
    long long num;
    cout<<"Enter some digits for sum: ";
    cin>>num;

    cout<<singledigit(num);
    
}
