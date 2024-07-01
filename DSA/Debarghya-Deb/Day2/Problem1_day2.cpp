#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int threshold;
    cout<<"Enter the threshold value : ";
    cin>>threshold;
    
    vector<int> v;
    int n;
    cout<< "Enter the number of students : ";
    cin>>n;

    

    for (int i = 0; i < n; i++)
    {
        int t;
        cout<<"Enter the arrival time of student " <<i+1<<" :";
        cin>>t;
        v.push_back(t);

    }
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] < 0){
            count++;
        }
    }
    
    if (count < threshold){
        cout<<"YES" << endl;
    }
    else{
        cout<< "NO" << endl;
    }
    
    
   
    
    return 0;
}