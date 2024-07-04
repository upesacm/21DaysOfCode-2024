#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 5;
    std::cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}