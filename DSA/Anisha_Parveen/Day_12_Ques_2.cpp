#include <bits/stdc++.h>
using namespace std;

int singleDigitNumber(int number)
{
    if (number < 10)
        return number;

    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return singleDigitNumber(sum);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int ans = singleDigitNumber(number);
    cout << "The single digit result is: " << ans << endl;
}
