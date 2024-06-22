#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<< "The no. of elements in the array : ";
    cin>>n;


    vector<int> v;

    int x;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter " << i+1<< " element :";
        cin>>x;
        v.push_back(x);

    }
    
    int target;
    cout<< "Enter day: " ;
    cin>>target;
    
    
    
    int window_size;
    cout<<"Enter the birth month : ";
    cin>>window_size;

    


    int count = 0;
    int i = 0;
    int j = i + window_size - 1;
    for (int i = 0; i < j && j < v.size() ; i++)
    {
        int sum = 0;
        for (int temp = i; temp <= j; temp++)
        {
            sum = sum + v[temp];
        }
        
        if(sum == target){
            count++;
        }
        j++;
    }
    
    cout<<count << endl;


    return 0;
}