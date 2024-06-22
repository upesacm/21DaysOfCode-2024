#include<iostream>
using namespace std;
int array_count(int arr[], int n, int k){
  int count = 0;
  for(int i = 1; i<n; i++){
    for(int j = i+1; j<=n; j++){
      if(i<j){
        if((i+j)%k==0){
          count++;
        }
      }
    }
  }
  return count;
}
int main(){
  int arr[] = {1,3,2,6,1,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int a = array_count(arr,n,3);
  cout<<"the count of sum of array is"<<a;
}
