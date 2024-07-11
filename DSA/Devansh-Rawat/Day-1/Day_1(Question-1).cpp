#include <bits/stdc++.h>
using namespace std;

int findways(int arr[],int arr_size,int days,int months){

    int sum=0;
   
    int output = 0;

    for (int i = 0; i <= arr_size; i++)
    {
        sum+=arr[i];
        if(i>=months){
            sum-=arr[i-months];
        }
        if(i>=months-1){
            if(sum==days) output++;
            
        }
            
    }
    
    return output;
    }

int main()
{
    // array
    int arr[]={2,2,1,3,2,2};
    int arr_size=sizeof(arr)/sizeof(int);
    cout << "The array is: ";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    //day input
    int day;
    cout << "Enter the day: ";
    cin >> day;

    // month input
    int month;
    cout << "Enter the month: ";
    cin >> month;

    // program calculation
    cout<<findways(arr,arr_size,day,month);
    
    return 0;
}

