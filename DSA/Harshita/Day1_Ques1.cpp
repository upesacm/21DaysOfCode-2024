#include<iostream>
using namespace std;
int arrayy(int arr[], int n, int day, int month){
  int count = 0;
  for(int i = 0; i<=n-month; i++){
    int sum = 0;
    for(int j = 0; j<month; j++){
      sum = sum+arr[i+j];
      if(sum == day){
        count++;
      }
    }
  }
  return count;
}
int main(){
  int arr[] = {2,2,1,3,2};
  int day = 4, month = 2;
  int n = sizeof(arr)/sizeof(arr[0]);
  int a = arrayy(arr,n,day,month);
  cout<<a;
}
