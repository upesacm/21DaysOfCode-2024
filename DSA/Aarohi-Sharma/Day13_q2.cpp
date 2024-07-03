#include<iostream>
using namespace std;
int check(int n, int rev){
    if (n==0){
        return rev;
    }
    rev=(rev*10)+(n%10);
    check(n/10, rev);
}
bool pall(int n){
    int rev= check(n, 0);
    return rev==n;
}
int main(){
    int n;
    cin>>n;
    if (pall(n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
