#include<iostream>
using namespace std;

int Pairs(int arr[],int size,int k){
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if((arr[i]+arr[j])%k==0 && i<j && i!=j){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[6]={1,3,2,6,1,2};
    int k;
    cout<<"Enter the value of k:";
    cin>>k;
    int count= Pairs(arr,6,k);
    cout<<"Number of (i,j) pairs divisible by k are:"<<count;
}