#include <bits/stdc++.h>
using namespace std;

int fibonacciNumber(int number)
{
    if (number <= 1)
        return number;

    return fibonacciNumber(number - 1) + fibonacciNumber(number - 2);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int ans = fibonacciNumber(number);
    cout << "Fibonacci number at position " << number << " is: " << ans << endl;
}
