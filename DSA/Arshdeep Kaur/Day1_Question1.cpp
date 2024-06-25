#include <iostream>
using namespace std;

int main() {
    int candy[10], n, day, month, count = 0;
    cout << "Enter the number of chocolate squares: ";
    cin >> n;
    cout << "Enter the chocolate squares: ";
    for (int i=0; i<n; i++) {
        cin >> candy[i];
    }

    cout << "Enter the day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> month;

    for (int i = 0; i <= n - month; ++i) {
        int sum = 0;
        for (int j = 0; j < month; ++j) {
            sum += candy[i + j];
        }
        if (sum == day) {
            count++;
        }
    }

    cout << count << endl;
}
