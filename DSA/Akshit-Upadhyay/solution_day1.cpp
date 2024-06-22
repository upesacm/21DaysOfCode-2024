#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int month, day;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the day: ";
    cin >> day;

    int fixed = 0;
    int j = month - 1;
    int sum = 0;
    int count = 0;

    while (j < n) {
        for (int i = fixed; i <= j; i++) {
            sum += arr[i];
        }
        if (sum == day) {
            count++;
        }
        sum = 0;
        fixed++;
        j++;
    }

    cout << count << endl;

    return 0;
}
