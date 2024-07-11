#include<iostream>
using namespace std;
int main(){

    int size,th,count=0;
    cout<<"Enter Size of Array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter Array Elements: ";

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter Threshold :";
    cin>>th;

    for(int i=0;i<size;i++){
        if(arr[i]<=0){
            count++;
        }
    }
    if(count>=th){
        cout<<"N0";
    }
    else{
        cout<<"YES";
    }
    return 0;
}
