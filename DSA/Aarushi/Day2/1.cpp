//Question:1
/*
A professor has a class of students and wants to know if the class should be cancelled based on student arrival times. The class is cancelled if fewer than a threshold number of students arrive on time.
Inputs:
An integer representing the threshold number of students.
An array of integers representing arrival times, where a non-positive integer indicates on-time arrival. Output:
YES" if the class is cancelled, "NO" otherwise.
Example:
threshold = 3

arrival_times = [-1, -3, 4, 2]

Output: YES
*/

#include <iostream>
#include<vector>
using namespace std;

int ClassStatus(const vector<int> &arr, int threshold){
    int onTime = 0;
    for(int i=0; i<arr.size(); i++){
        if (arr[i]<=0)
        onTime++;
    }
    if (onTime<threshold)
    return 1;
    else
    return 0;
}

int main(){
    int threshold;
    cout<< "Enter the threshold number of students:";
    cin>>threshold;

    int n;
    cout<< "Enter the number of students in the class:";
    cin>>n;

    vector<int> arr(n);
    cout<< "Enter the arrival times of students (non-positive for on-time):";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int result = ClassStatus(arr, threshold);
    if (result == 1) {
        cout << "The class is canceled: YES" << endl;
    } else {
        cout << "The class is canceled: NO" << endl;
    }

    return 0;
}