#include<iostream>
using namespace std;
int main(){
    int size,k;
    cout<<"Enter Size of Array : ";
    cin>>size;
    int arr[size];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter K : ";
    cin>>k;

    int count=0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((arr[i]+arr[j])%k==0){
                count++;
            }
        }
    }
    cout<<"Output : "<<count;

    return 0;
}
