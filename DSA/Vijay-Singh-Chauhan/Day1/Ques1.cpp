#include<iostream>
using namespace std;

int main(){
    int size,day,month;
    cout<<"Enter Size of Array : ";
    cin>>size;
    cout<<" Enter Day : ";
    cin>>day;
    cout<<"Enter Month : ";
    cin>>month;


    int arr[size];
    cout<<"Enter Array Elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int count=0;

    for(int i=0;i<=size-month;i++){
        int sum=0;
        for(int j=i;j<i+month;j++){
            sum=sum+arr[j];
        }
        if(sum%day==0){
            count++;
        }
    }
    cout<<"Output : "<<count;

    return 0;

}
