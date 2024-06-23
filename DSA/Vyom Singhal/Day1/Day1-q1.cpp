#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int *arr = new int [n];
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int day, month, count = 0;
    cout << "Enter day and month : ";
    cin >> day >> month;
    for(int i = 0; i <= n -month; i++) {
        int sum = 0;
        for(int j = i; j < i+month; j++) {
            sum += arr[j];
        }
        if(sum == day) count++;
    }
    cout << "Unique ways : " << count;
}
