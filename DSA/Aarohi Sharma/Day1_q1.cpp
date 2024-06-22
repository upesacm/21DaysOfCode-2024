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
    int d, m;
    cin>>d>>m;
    int sum=0, count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+m-1; j++){
            sum=array[i]+array[j];
            if(sum==d){
                count++;
            }
        }
    }
    cout<<count;
}
