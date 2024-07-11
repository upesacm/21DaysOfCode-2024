#include <iostream>

using namespace std;

int sumDigits(int num) {

    if (num < 10) {
        return num;
    }

    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sumDigits(sum);
}

int main() {
    int number;

    cout << "Enter a large integer: ";
    cin >> number;

    int result = sumDigits(number);
    cout << "The single digit result is: " << result << endl;

    return 0;
}
