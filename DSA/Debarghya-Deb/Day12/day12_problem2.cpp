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
    int number = 9875;
    cout<<"Enter your number here : " ;
    cin>>number;
    cout << "The single digit result of " << number << " is: " << sumDigits(number) << endl;
    return 0;
}
