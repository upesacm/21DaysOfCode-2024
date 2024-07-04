#include<iostream>
using namespace std;

int fibonacci(int num){
    if(num==1 || num==0){
        return num;
    }
    return fibonacci(num-1)+fibonacci(num-2);

}
int main(){
    int num;
    cout<<"Enter Integer: ";
    cin>>num;

    cout<<fibonacci(num);
    return 0;
}
