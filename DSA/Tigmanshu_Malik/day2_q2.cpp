#include<iostream>
#include<vector>
using namespace std;

int no_of_ways(vector<int> arr , int day, int month){

    int count = 0;
    int n = arr.size();
    
    if (n < month) 
        return 0;
    
    int sum = 0;

    for (int i = 0; i < month; i++) {
        sum += arr[i];
    }
    if (sum == day) {
        ++count;
    }
    

    for (int i = month; i < n; ++i) {

        sum += arr[i] - arr[i - month];
        
        if (sum == day) 
            count++;
        
    }
    
    return count;
}