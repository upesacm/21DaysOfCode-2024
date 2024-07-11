#include <iostream>
using namespace std;

int main() {
    int arrival_times[100], n, threshold;
    cout << "Enter the threshold number of students: ";
    cin >> threshold;
    cout << "Enter the number of arrival times: ";
    cin >> n;
    cout << "Enter the arrival times: ";
    for (int i=0; i<n; i++) {
        cin >> arrival_times[i];
    }
    int count = 0;
    for (int i=0; i<n; i++) {
        if (arrival_times[i] < 0) {
            count++;
        }
    }

    if (count < threshold) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
