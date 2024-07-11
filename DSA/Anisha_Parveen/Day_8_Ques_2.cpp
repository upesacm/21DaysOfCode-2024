#include <bits/stdc++.h>
using namespace std;

queue<int> q1, q2;

void push(int x)
{
    q1.push(x);
}

int pop()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int element = q1.front();
    q1.pop();

    swap(q1, q2);

    return element;
}
int top()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int element = q1.front();

    q2.push(element);
    swap(q1, q2);

    return element;
}

bool empty()
{
    return q1.empty();
}

int main()
{
    push(1);
    push(2);

    cout << "Top Operation: " << top() << endl;
    cout << "Pop Operation: " << pop() << endl;
    cout << "Pop Operation after removing \"2\" from the stack: " << top() << endl;

    return 0;
}
