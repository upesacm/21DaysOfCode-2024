#include<iostream>
using namespace std;
int sum(int num){
    int s=0;
    if(num==0){
        return 0;
    }
    return ((num%10)+sum(num/10));
}
int main(){
    int num;
    cin>>num;
    cout<<sum(num)/10<<endl;
}