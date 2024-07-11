#include<bits/stdc++.h>
using namespace std;

void digitSum(int n){
    if(n<10){
        cout << n;
        return;
    }
    int sum=0;
    while (n != 0) { 
        int r=n%10;
        n=n/10;
        sum=sum+r;
    }
    digitSum(sum);
}

int main(){
    int n=9875;
    digitSum(n);
    return 0;
}