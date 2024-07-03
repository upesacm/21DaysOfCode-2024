#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Error: enter a positive number." << endl;
        return 1;
    }
    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;
    return 0;
}
