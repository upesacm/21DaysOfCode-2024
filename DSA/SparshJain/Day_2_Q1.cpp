#include<iostream>
using namespace std;
int Check(int arr[],int time){
    int count=0;
    for(int i=0;i<time;i++){
        if(arr[i]<=0){
            count++;
        }
        
    }
    return count;
}
int main(){
    int thresh;
    cout<<"Input the threshold no of students";
    cin>>thresh;
    int time;
    cout<<"Enter the total no of arrival times \n";
    cin>>time;
    int At[time];
    cout<<"Input the array of arrival times\n";
    for(int i=0;i<time;i++){
        cin>>At[i];
        

    }
    int result=Check(At,time);
    if(result<thresh){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}