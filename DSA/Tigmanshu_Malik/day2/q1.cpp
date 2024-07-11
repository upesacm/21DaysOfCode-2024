#include<iostream>
#include<vector>
using namespace std;

bool classCancel(vector<int> arr, int thresh){

    int count = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] <= 0) {
            count++;
        }
        if (count > thresh) {
            return false;  
        }
    }

    return count <= thresh;    
}