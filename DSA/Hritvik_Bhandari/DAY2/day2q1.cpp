#include <iostream>
using namespace std;
bool classav(int arr[],int size,int threshold){
    int count=0;
    for(int i = 0 ; i<size;i++){
        if(arr[i]<0){
             count++;
        }
    }
    if(count<threshold){
        return false;
    }
    return true;
}
int main()
{
    int students;
    cout<<"Enter the number of students ";
    cin>>students;
    int threshold;
    cout<<"enter the threshold no. of students ";
    cin>>threshold;
    int arrival_time[students];
    for(int i = 0;i<students;i++){
        cin>>arrival_time[i];
    }
   int lecture = classav(arrival_time,students,threshold);
   if(lecture) 
      cout<<"NO";
   else 
      cout<<"YES";
   return 0;
}
