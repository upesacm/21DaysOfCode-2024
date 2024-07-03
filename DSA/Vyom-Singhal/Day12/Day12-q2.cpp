#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n < 10) return n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sumDigits(sum);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Output : " << sumDigits(n);
}