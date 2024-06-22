#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int count = 0;

    int k;
    cout<<"k : ";
    cin>>k;

    vector<int> v;
    int n;
    cout<<"The no. of elements you want to enter in the array : ";
    cin>>n;

    int x;
    

    // This is the array
    for(int i = 0 ; i < n; i ++){
        cout<< "Enter the element : ";
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i <  v.size() ; i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if( (v[i] + v[j]) % k == 0  ){
                count++;
            }
        }
        
    }

    cout<< "Output : "<<count << endl;
    
    return 0;
}