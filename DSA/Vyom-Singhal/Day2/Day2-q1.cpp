#include<iostream>
using namespace std;

bool classCancelOrNot(int *arr, int n, int threshhold) {
    int count;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) count++;
    }
    if(count >= threshhold) return true;
    else return false;
}

int main() {
    int threshhold;
    cout << "Enter threshhold : ";
    cin >> threshhold;
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int *arr = new int [n];
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool classHappening = classCancelOrNot(arr,n,threshhold);
    if(classHappening == true) cout << "YES";
    else cout << "NO";
}
