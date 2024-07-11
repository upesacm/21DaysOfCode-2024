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
    int t, count=0;
    cin>>t;
    for(int i=0; i<n; i++){
        if (array[i]<0){
            count++;
        }
    }
    if(count<t){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
