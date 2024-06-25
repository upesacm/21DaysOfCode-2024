#include <iostream>
using namespace std;

int main() {
    int arr[10], n, k, pairs=0;
    cout << "Enter the number of elements of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i] < arr[j]) {
                int sum = arr[i] + arr[j];
                if (sum % k == 0) {
                    pairs++;
                }
            }
        }
    }

    cout << pairs;
}
