#include <bits/stdc++.h>
using namespace std;

vector<int> stackArray;

void push(int data)
{
    stackArray.push_back(data);
}

void top()
{
    cout << stackArray[stackArray.size() - 1] << "\n";
}

void pop()
{
    stackArray.erase(stackArray.end() - 1);
}

void maxElement()
{
    int temp = 0;
    for (int i = 0; i < stackArray.size(); i++)
    {
        temp = max(temp, stackArray[i]);
    }
    cout << "\nThe max element in the stack is : " << temp;
}

int main()
{
    push(1);
    push(2);
    maxElement();
    pop();
    maxElement();
    return 0;
}