#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    cout<<"Enter elements:";
    for (int i=0; i<n; i++){
        cin>>array[i];
    }
    for (int i=0; i<n; i++){
        cout<<array[i]<<endl;
    }
    int k;
    cin>>k;
    int count=0;
    for(int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if ((i+j)%k==0){
                count++;
            }
        }
    }
    cout<<count;
}
