#include <iostream>
using namespace std;

int validWaysToDivideBar(int no_of_squares, int candy[], int birth_day, int birth_month)
{
    int count = 0;

    for (int i = 0; i <= (no_of_squares - birth_month); i++)
    {
        int sum = candy[i];

        for (int j = i + 1; j < (birth_month + i); j++)
        {
            sum += candy[j];
        }

        if (sum == birth_day)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int no_of_squares;
    cout << "Enter the no_of_squares present in the candy: ";
    cin >> no_of_squares;

    int candy[100];

    cout << "Input values of squares in the candy: ";

    for (int i = 0; i < no_of_squares; i++)
    {
        cin >> candy[i];
    }

    int birth_day;
    cout << "Enter the birth date of Raju : ";
    cin >> birth_day;

    int birth_month;
    cout << "Enter the birth month of Raju : ";
    cin >> birth_month;

    int result = validWaysToDivideBar(no_of_squares, candy, birth_day, birth_month);
    cout << "The number of valid ways to divide the candy are: " << result;
}
