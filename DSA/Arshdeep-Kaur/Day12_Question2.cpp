#include <iostream>

using namespace std;

int sum_digit(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum_digit(sum);
    }
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    int result = sum_digit(num);
    cout << "The result is: " << result << endl;

    return 0;
}
