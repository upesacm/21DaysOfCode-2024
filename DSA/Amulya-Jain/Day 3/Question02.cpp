#include <iostream>
#include <string>
using namespace std;

string isStringSymmetrical(const string &input)
{
    int length = input.length();

    for (int i = 0; i < length / 2; i++)
    {
        if (input[i] != input[length - 1 - i])
            return "not symmetrical";
    }

    return "symmetrical";
}

int main()
{
    string str = "acxz";
    cout << isStringSymmetrical(str) << endl;
    return 0;
}
